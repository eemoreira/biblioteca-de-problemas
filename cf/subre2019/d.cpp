#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  vector<int> p(n, -1);
  for (int i = 1; i <  n; i++) {
    int v;
    cin >> v;
    --v;
    p[i] = v;
    adj[i].emplace_back(v);
    adj[v].emplace_back(i);
  }
  vector<int> dads(n,1);
  function<void(int,int)> Dfs = [&](int v, int x) {
    for (auto u : adj[v]) {
      if (u != x) {
        dads[u] = dads[v] + 1;
        Dfs(u,v);
      }
    }
  };
  Dfs(0,0);
  vector<pair<int,int>> le;
  for (int i = 0; i < n; i++) {
    le.emplace_back(dads[i], i);
  }
  sort(le.begin(), le.end());
  reverse(le.begin(), le.end());
  long long ans = 0;
  int ptr = 0;
  vector<int> y, vis(n);
  for (int i = 0; i < n; i++) {
    ptr += 1;
    int t = le[i].second;
    int now = 0;
    while (~t && !vis[t]) {
      vis[t] = 1;
      now += 1;
      t = p[t];
    }
    y.emplace_back(now);
  }
  sort(y.begin(), y.end());
  reverse(y.begin(), y.end());
  for (int i = 0; i < min(n,k); i++) ans +=  y[i];
  cout << ans << '\n';
}
