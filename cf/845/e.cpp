#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MAX = 2e5 + 5;
vector<pair<int,int>> adj[MAX];
vector<vector<int>> ord;
vector<int> vis, cp, go;
int n,m;

void dfs1(int v, vector<vector<int>>& Adj) {
  vis[v] = 1;
  for (auto u : Adj[v]) {
    if (!vis[u]) {
      dfs1(u,Adj);
    }
  }
  go.emplace_back(v);
}

void dfs2(int v, vector<vector<int>>& Adj) {
  vis[v] = 1;
  cp.emplace_back(v);
  for (auto u : Adj[v]) {
    if (!vis[u]) {
      dfs2(u,Adj);
    }
  }
}
int size(int v, vector<vector<int>>& Adj, vector<int>& sz) {
  vis[v] = 1;
  sz[v] = 1;
  for (auto u : Adj[v]) {
    if (!vis[u]) {
      sz[v] += size(u,Adj,sz);
    }
  }
  return sz[v];
}

bool check(int k) {
  int mx = ord[k][0];
  vector<vector<int>> Adj_now(n), rev(n);
  for (int i = 0; i < n; i++) {
    for (auto [u,w] : adj[i]) {
      Adj_now[i].emplace_back(u);
      rev[u].emplace_back(i);
      if (w <= mx) {
        Adj_now[u].emplace_back(i);
        rev[i].emplace_back(u);
      }
    }
  }
  go.clear();
  vis.assign(n,0);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs1(i,Adj_now);
    }
  }
  vis.assign(n,0);
  reverse(go.begin(),go.end());
  vector<int> roots(n), root_nodes;
  vector<vector<int>> adj_scc(n);
  dbg(go);
  for (auto u : go) {
    if (!vis[u]) {
      dfs2(u,rev);
      int root = cp[0];
      for (auto x : cp) {
        roots[x] = root;
      }
      dbg(cp);
      root_nodes.emplace_back(root);
      cp.clear();
    }
  }
  for (int v = 0; v < n; v++) {
    for (auto u : Adj_now[v]) {
      if (roots[v] != roots[u]) {
        adj_scc[roots[v]].emplace_back(roots[u]);
      }
    }
  }
  dbg(k);
  dbg(ord);
  dbg(Adj_now);
  dbg(adj_scc);
  vis.assign(n,0);
  go.clear();
  for (auto u : root_nodes) {
    if (!vis[u]) {
      dfs1(u,adj_scc);
    }
  }
  dbg(root_nodes, go);
  assert((int)go.size() > 0);
  vis.assign(n,0);
  vector<int> sz(n,0);
  return size(go.back(),adj_scc,sz) == (int)root_nodes.size();
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  ord.clear();
  for (int i = 0; i < m; i++) {
    int v,u,w;
    cin >> v >> u >> w;
    --v; --u;
    adj[v].emplace_back(u,w);
    vector<int> q = {w,v,u};
    ord.emplace_back(q);
  }
  ord.push_back({0,0,0});
  sort(ord.begin(), ord.end());
  int l = 0, r = ord.size() - 1;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = ord[mid][0];
    }
    else {
      l = mid + 1;
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





