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
  multiset<pair<int,int>> pq;
  for (auto &u : a) {
    cin >> u;
  }
  if (a == vector<int>(n, a[0])) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    pq.emplace(a[i],i);
  }
  vector<pair<int,int>> ans;
  bool ok = true;
  while (ok) {
    auto mn = *pq.begin();
    if (mn.first == 1) {
      cout << -1 << '\n';
      return;
    }
    pq.erase(mn);
    multiset<pair<int,int>> now;
    ok = false;
    now.emplace(mn);
    while (!pq.empty()) {
      auto t = *pq.begin();
      pq.erase(pq.begin());
      if (t.first == mn.first) {
        now.emplace(t);
        continue;
      }
      ok = true;
      now.emplace((t.first + mn.first - 1) / mn.first, t.second);
      ans.emplace_back(t.second, mn.second);
    }
    pq = now;
  }
  cout << ans.size() << '\n';
  for (auto u : ans) {
    cout << u.first+1 << ' ' << u.second+1 << '\n';
  }
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





