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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  vector<map<int,int>> f(n);
  vector<long long> ans(n);
  vector<int> mx(n);
  vector<int> who(n);
  iota(who.begin(), who.end(), 0);
  function<void(int,int)> Dfs = [&](int v, int p) {
    vector<int> ord;
    for (auto u : adj[v]) {
      if (u != p) {
        Dfs(u,v);
        ord.emplace_back(u);
      }
    }
    if (ord.empty()) {
      f[v][a[v]]++;
      ans[v] = a[v];
      mx[v] = 1;
      return;
    }
    sort(ord.begin(), ord.end(),[&](int l,int r){ return f[who[l]].size() > f[who[r]].size();});
    dbg(v,ord);
    who[v] = who[ord[0]];
    f[who[v]][a[v]]++;
    ans[v] = ans[ord[0]];
    mx[v] = mx[ord[0]];
    if (f[who[v]][a[v]] > mx[v]) {
      ans[v] = 0;
      mx[v] = f[who[v]][a[v]];
    }
    if (f[who[v]][a[v]] == mx[v]) {
      ans[v] += a[v];
    }
    for (int i = 1; i < (int)ord.size(); i++) {
      for (auto u : f[who[ord[i]]]) {
        f[who[v]][u.first] += u.second;
        if (f[who[v]][u.first] > mx[v]) {
          ans[v] = 0;
          mx[v] = f[who[v]][u.first];
        }
        if (f[who[v]][u.first] == mx[v]) {
          ans[v] += u.first;
        }
      }
    }
  };
  Dfs(0,0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
}






