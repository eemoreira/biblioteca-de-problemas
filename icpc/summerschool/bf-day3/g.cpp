#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "codes/debug.h"
#else
#define dbg(...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> Adj(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    Adj[u].emplace_back(v);
    Adj[v].emplace_back(u);
  }
  vector<int> ans(n,1);
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    mn = min(mn, (int)Adj[i].size());
  }
  for (int i = 0; i < n; i++) {
    if ((int)Adj[i].size() == mn) {
      ans[i] = 0;
      for (auto u : Adj[i]) {
        ans[u] = 0;
      }
      break;
    }
  }
  for (auto u : ans) {
    cout << u << ' ';
  }
  cout << '\n';
}




