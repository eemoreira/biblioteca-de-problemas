#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
ll f[maxn];
int n;

void clear() {
    for (int i = 0; i <= n; i++) f[i] = 0;
}

void update(int i, int v) {
    while (i <= n) {
        f[i] += v;
        i += i & -i;
    }
}

ll query(int i) {
    ll ans = 0;
    while (i) {
        ans += f[i];
        i -= i & -i;
    }
    return ans;
}

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto &u : a) cin >> u;
    vector<ll> ans(n + 1);
    ll delta = 0;
    clear();
    for (int i = 0; i < n; i++) {
        delta += a[i];
        update(i + 1, a[i]);
        update(i + 2, -a[i]);
    }
    for (int i = n; i >= 1; i--) {
        ll v = query(i);
        if (v == 0) continue;
        if (v == i) {
            ans[i] = 1;
        }
        update(i - delta/i + 1, -1);
        update(i, 1);
        delta -= delta/i + v - 1;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
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





