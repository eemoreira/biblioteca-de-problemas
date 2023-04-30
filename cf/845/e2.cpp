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
vector<int> vis, ord, go;
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
  int mx = ord[k];
  vector<vector<int>> Adj_now(n);
  for (int i = 0; i < n; i++) {
    for (auto [u,w] : adj[i]) {
      Adj_now[i].emplace_back(u);
      if (w <= mx) {
        Adj_now[u].emplace_back(i);
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
  vector<int> sz(n,0);
  return size(go.back(),Adj_now,sz) == n;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  ord = {0};
  for (int i = 0; i < m; i++) {
    int v,u,w;
    cin >> v >> u >> w;
    --v; --u;
    adj[v].emplace_back(u,w);
    ord.emplace_back(w);
  }
  sort(ord.begin(), ord.end());
  int l = 0, r = ord.size() - 1;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = ord[mid];
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





