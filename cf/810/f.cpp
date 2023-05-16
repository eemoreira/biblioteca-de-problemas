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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
        cnt[v]++;
        cnt[u]++;
    }
    for (int v = 0; v < n; v++) {
        int x = cnt[v];
        int y = n - 1 - cnt[v];
        bool ok = y % x == 0;
        for (auto u : adj[v]) {
            ok &= (cnt[u] - 1) == y / x;
        }
        if (ok) {
            cout << x << ' ' << y/x << '\n';
            return;
        }
    }
    assert(false);
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





