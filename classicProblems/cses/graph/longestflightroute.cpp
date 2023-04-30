#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int nx[maxn];
ii y[maxn];
int n, m;

ii dfs(int v) {
    if (y[v].first != -1e9) return y[v];
    y[v] = {0, v == n - 1};
    for (auto u : adj[v]) {
        auto [d, f] = dfs(u);
        if (d + 1 > y[v].first && f) {
            y[v] = {d + 1, 1};
            nx[v] = u;
        }
    }
    return y[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        y[i] = {-1e9, 0};
        nx[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[u].emplace_back(v);
    }

    if (!dfs(0).second) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int end = 0;
    vector<int> ans;
    while (end != -1) {
        ans.emplace_back(end + 1);
        end = nx[end];
    }
    cout << ans.size() << '\n';
    for (auto u : ans) cout << u << ' ';
    cout << '\n';
}





