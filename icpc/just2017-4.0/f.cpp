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

namespace manacher {
    long long n, count = 0;
    vector<int> d1, d2;
    void solve_odd(string &s) {
        d1.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
                int k = (i > r) ? 1:min(d1[l+r-i], r-i+1);
            while (0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
            count += d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
    }
    void solve_even(string &s) {
        d2.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0:min(d2[l+r-i+1], r-i+1);
            while (0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
            count += d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
    }
    long long solve(string &s) {
        n = s.size();
        count = 0;
        solve_odd(s);
        solve_even(s);
        return count;
    }
}
struct node {
    ll mx, pos;
    node() {
        mx = -1;
        pos = 1e9;
    }
    node(ll _mx, int _pos) : mx(_mx), pos(_pos) {
    }
};

node comp(node a, node b) {
    if (a.mx != b.mx) {
        return a.mx > b.mx ? a : b;
    }
    return a.pos < b.pos ? a : b;
}

const int MAX = 1e4 + 5;
const node neutral = node(-1, 1e9);

int p2[MAX];
const int lg = 20;
vector<node> sparse[lg];
vector<node> a;
int n;

namespace sparseTable{
    void build(){ // dont forget to compute p2, change neutral/comp
        for(int i = 0; i < lg; i++){
            sparse[i] = vector<node>(n, neutral);
        }
        for(int i = 0; i < n; i++){
            sparse[0][i] = a[i];
        }
        for(int i = 0; i < lg-1; i++){
            for(int j = 0; j + (1 << (i+1)) <= n;  j++){
                sparse[i+1][j] = comp(sparse[i][j], sparse[i][j + (1 << i)]);
            }
        }
    }
    node getvalue(int l, int r){
        int last = p2[r-l];
        return comp(sparse[last][l], sparse[last][r - (1 << last)]);
    }
}

void solve() {
    int q;
    cin >> n >> q;
    unordered_map<string, int> idx;
    a = vector<node>(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        idx[s] = i;
        a[i] = node(manacher::solve(s), i);
    }

    sparseTable::build();
    
    while (q--) {
        string s, t;
        cin >> s >> t;
        int l = idx[s];
        int r = idx[t];
        if (l > r) swap(l, r);
        cout << sparseTable::getvalue(l, r + 1).pos + 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    p2[0] = p2[1] = 0;
    for (int i = 2; i < MAX; i++) p2[i] = p2[i >> 1] + 1;
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





