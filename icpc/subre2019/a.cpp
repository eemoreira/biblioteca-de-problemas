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
  int n, m, k;
  cin >> m >> n >> k;
  vector<vector<int>> a(k + 1, vector<int>(3));
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  dbg(a);
  vector<vector<int>> adj(k + 3);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      if (i == j) continue;
      long long y = abs(a[i][0] - a[j][0]);
      y *= y;
      long long x = abs(a[i][1] - a[j][1]);
      x *= x;
      long long r1 = a[i][2];
      long long r2 = a[j][2];
      long long t = r1 + r2;
      t *= t;
      if (t >= y + x) {
        adj[i].emplace_back(j);
      }
    }
  }
  bool ok = true;
  vector<int> vis(k + 3);
  function<void(int)> Dfs = [&](int v) {
    vis[v] = 1;
    dbg(v);
    if (v == k+1) {
      ok = false;
    }
    for (auto u : adj[v]) {
      if (!vis[u]) {
        Dfs(u);
      }
    }
  };
  for (int j = 1; j <= k; j++) {
    if (a[j][0] + a[j][2] >= m) {
      adj[j].emplace_back(0);
      adj[0].emplace_back(j);
    }
    if (a[j][1] - a[j][2] <= 0) {
      adj[j].emplace_back(0);
      adj[0].emplace_back(j);
    }
    if (a[j][1] + a[j][2] >= n) {
      adj[j].emplace_back(k+1);
      adj[k+1].emplace_back(j);
    }
    if (a[j][0] - a[j][2] <= 0) {
      adj[j].emplace_back(k+1);
      adj[k+1].emplace_back(j);
    }
  }
  dbg(adj);
  Dfs(0);
  cout << (ok ? "S\n": "N\n");
}







