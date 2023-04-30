#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        --x; --y;
        adj[i].emplace_back(x);
        adj[i].emplace_back(y);
    }
    vector<int> vis(n), ans(n,1);
    int going = 0;
    int other = 0;
    function<void(int)>  dfs = [&](int v) {
        vis[v]++;
        for (auto u : adj[v]) {
            if (u == going) {
                vis[going]++;
            }
            if (u == other) {
                vis[other]++;
            }
        }
        if (vis[going]) return;
        vis[other] = 0;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                dfs(u);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            vis.assign(n,0);
            other = u == adj[i][0] ? adj[i][1] : adj[i][0];
            going = i;
            dfs(u);
            if (vis[other] && vis[going]) {
                ans[i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (ans[i] ? 'N' : 'Y');
    }
    cout << '\n';
    return 0;
}





