#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

#define comp(a,b) min(a,b)
const int neutral = 1e9;

template<typename T>
class SegTree {
    private:
        vector<T> tree;
        int n;
        int le(int i) { return 2*i;}
        int ri(int i) { return 2*i + 1;}
        void build(int v, int l, int r, vector<T> &a) {
            if (l == r) {
                tree[v] = a[l];
                return;
            }
            int mid = (l+r)>>1;
            build(le(v), l, mid, a);
            build(ri(v), mid+1, r, a);
            tree[v] = comp(tree[le(v)], tree[ri(v)]);
        }
        void update(int v, int l, int r, int pos, T val) {
            if (l > pos || r < pos) return;
            if (l == r) {
                tree[v] = val;
                return;
            }
            int mid = (l+r)>>1;
            if (pos <= mid) {
                update(le(v), l, mid, pos, val);
            }
            else {
                update(ri(v), mid+1, r, pos, val);
            }
            tree[v] = comp(tree[le(v)], tree[ri(v)]);
        }
        T query (int v, int l, int r, int L, int R){
            if (l > R || r < L) return neutral;
            if (l >= L && r <= R) {
                return tree[v];
            }
            int mid = (l+r)>>1;
            return comp(query(le(v), l, mid, L, R), query(ri(v), mid+1, r, L, R));
        }
    public:
        SegTree (vector<T> &v) {
            n = v.size();
            tree.assign(4*n, neutral);
            build(1,1,n,v);
        }
        SegTree (int _n) {
            n = _n;
            tree.assign(4 * n, neutral);
            vector<ll> trash(n + 1, neutral);
            build(1,1,n,trash);
        }
        void update (int pos, T val) {
            update(1,1,n,pos,val);
        }
        T query (int l, int r) {
            return query(1,1,n,l,r);
        }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> mx(n + 1, vector<int>(n + 1, 0)), mn(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++) {
        mx[i][i] = a[i];
        mn[i][i] = a[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = j;
            int r = j + i - 1;
            if (r <= n) {
                mx[l][r] = max(a[r], mx[l][r - 1]);
                mn[l][r] = min(a[r], mn[l][r - 1]);
            }
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = j;
            int r = j + i - 1;
            if (r <= n) {
                dp[l][r] = r - l;
                int L = l, R = r - 1;
                int now = -1;
                while (L <= R) {
                    int k = (L + R) >> 1;
                    if (mx[l][k] <= mn[k + 1][r]) {
                        now = k;
                        L = k + 1;
                    }
                    else {
                        R = k - 1;
                    }
                }
            }
        }
    }
    ll ans = 0;
    dbg(dp);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





