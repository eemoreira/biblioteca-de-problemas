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
int vis[maxn];
 
vector<int> go;

bool dfs(int v) {
    vis[v] = 1;
    bool ok = true;
    for (auto u : adj[v]) {
        if (vis[u] == 1) return false;
        else if (!vis[u]) ok &= dfs(u);
    }
    go.emplace_back(v);
    vis[v] = 2;
    return ok;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
    }
    for (int i = 0; i < n; i++) if (!vis[i]) {
        if (!dfs(i)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    reverse(go.begin(), go.end());
    for (auto u : go) cout << u+1 << ' ';
    cout << '\n';
}
