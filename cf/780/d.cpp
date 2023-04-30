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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<pair<int,int>>> gp;
  vector<pair<int,int>> go;
  vector<int> p(n+1), neg(n+1);
  for (int i = 0; i < n; i++) {
    p[i+1] = p[i] + (abs(a[i]) == 2);
    neg[i+1] = neg[i] + (a[i] < 0);
    if (a[i]) {
      go.emplace_back(a[i],i);
    }
    else if (!go.empty()) {
      gp.emplace_back(go);
      go = {};
    }
  }
  if (!go.empty()) {
    gp.emplace_back(go);
  }
  pair<int,pair<int,int>> ans = {0, pair<int,int>(0,n)};
  int qnt = 0;
  dbg(gp);
  dbg(p, neg);
  for (auto u : gp) {
    int t = u.size() - 1;
    for (int i = 0; i <= t; i++) {
      int l = i;
      int r = t;
      int rg = neg[u[t].second + 1] - neg[u[i].second];
      int mx = p[u[t].second + 1] - p[u[i].second];
      dbg(i, rg);
      if (rg % 2 == 0) {
        pair<int,pair<int,int>> now = {mx, pair<int,int>(u[i].second, n - u[t].second - 1)};
        ans = max(now, ans);
      }
      else {
        while (l <= r) {
          int mid = (l + r) >> 1;
          int g = neg[u[mid].second + 1] - neg[u[i].second];
          if (g == rg - 1) {
            dbg(u, g, mid);
            mx = p[u[mid].second + 1] - p[u[i].second];
            pair<int,pair<int,int>> now = {mx, pair<int,int>(u[i].second, n - u[mid].second - 1)};
            ans = max(now, ans);
            l = mid + 1;
          }
          else if (g < rg - 1) {
            l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
      }
    }
  }
  cout << ans.second.first << ' ' << ans.second.second << '\n';
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





