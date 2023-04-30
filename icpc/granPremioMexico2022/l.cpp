#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mx = 2e6;
int p[mx];
vector<int> adj[mx];

void pre(int v, int y) {
    p[v] = y;
    for (auto u : adj[v]) {
        if (u != y) {
            pre(u,v);
        }
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  --x;
  for (int i = 1; i < n; i++) {
      int u, v; 
      cin >> u >> v;
      --u; --v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
  }
  long long ans = 0;
  vector<int> add(n,1);
  add[0] = 0;
  int t = x;
  pre(0,0);
  while (p[t] != t) {
      add[t] = 0;
      t = p[t];
  }
  dbg(p[x]);
  dbg(add);
  function<void(int, int)> dfs = [&](int v, int y) {
      ans++;
      for (auto u : adj[v]) {
          if (u != y && u != p[x]) {
              dfs(u,v);
          }
      }
      ans += add[v];
  };
  if (p[x] != 0) {
      dfs(0,0);
  }
  cout << ++ans << '\n';
}





