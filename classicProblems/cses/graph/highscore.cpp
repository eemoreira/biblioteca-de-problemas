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

const int maxn = 5005;
i3 ed[maxn];
int n, m;
bool vis[maxn];
int reach[maxn], reach2[maxn];
vector<int> adj[maxn], rev[maxn];

void dfs(int v) {
    vis[v] = true;
    reach[v] = 1;
    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
    }
}

void dfs2(int v) {
    vis[v] = true;
    reach2[v] = 1;
    for (auto u : rev[v]) if (!vis[u]) {
        dfs2(u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        --v; --u;
        ed[i] = i3(v, u, -w);
        adj[v].emplace_back(u);
        rev[u].emplace_back(v);
    }
    dfs2(n - 1);
    memset(vis, false, sizeof(vis));
    dfs(0);
    vector<ll> d(n, 1e18);
    d[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            auto [v, u, w] = ed[j];
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
            }
        }
    }
    dbg(d);
    for (int i = 0; i < m; i++) {
        auto [v, u, w] = ed[i];
        if (!reach[v] || !reach2[u]) continue;
        if (d[v] != 1e18 && d[v] + w < d[u]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << -d[n-1] << '\n';
}





