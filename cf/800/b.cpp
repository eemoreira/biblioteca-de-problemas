#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    --v;
    adj[v].emplace_back(i);
    adj[i].emplace_back(v);
  }
  vector<pair<long long,long long>> rg(n);
  for (int i = 0; i < n; i++) {
    cin >> rg[i].first >> rg[i].second;
  }
  int ans = 0;
  function<void(int,int)> Dfs = [&](int v, int x) {
    if (v > 0 && (int)adj[v].size() == 1) {
      ans += 1;
      return;
    }
    for (auto u : adj[v]) {
      if (u != x) {
        Dfs(u,v);
      }
    }
    long long mx = 0;
    for (auto u : adj[v]) {
      if (u != x) {
        mx += rg[u].second;
      }
    }
    bool ok = rg[v].first <= mx;
    if (ok) {
      rg[v].second = min(rg[v].second,mx);
    }
    else {
      ans += 1;
    }
  };
  Dfs(0,0);
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





