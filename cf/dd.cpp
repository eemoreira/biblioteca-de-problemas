#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
 
/* stop freaking out pls */
 
 
void solve() {
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    --v;
    a[v]++;
  }
  bool ok = false;
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    ok |= a[v] && a[u];
  }
  queue<int> q;
  vector<int> d(n,1e9);
  d[n-1] = 0;
  q.emplace(n-1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : adj[v]) {
      if (d[u] > d[v] + 1) {
        d[u] = d[v] + 1;
        q.emplace(u);
      }
    }
  }
  vector<int> vis(n);
  vector<int> cnt(m+1);
  function<void(int)> Dfs = [&](int v) {
    vis[v] = 1;
    for (auto u : adj[v]) {
      if (!vis[u]) {
        if (a[u]) {
          cnt[d[u]]++;
        }
        Dfs(u);
      }
    }
  };
  Dfs(n-1);
  for (auto u : cnt) {
    ok |= u > 1 || (u && u > d[0]);
  }
  int mn = 1e9;
  if (ok) {
    mn = 0;
  }
  dbg(cnt);
  for (int i = 0; i <= m; i++) {
    if (cnt[i]) {
      int ptr = i;
      for (int j = i+1; j <= m; j++) {
        i = j;
        if (cnt[j]) {
          mn = min(mn, j-ptr-1);
          break;
        }
      }
    }
  }
  dbg(d);
  cout << d[0] - mn << '\n';
}
