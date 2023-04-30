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
  int n;
  cin >> n;
  vector<vector<int>> rod(3);
  vector<vector<int>> f(3, vector<int>(n+1));
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    rod[0].emplace_back(v);
    f[0][v] += 1;
  }
  vector<pair<int,int>> ans;
  int k = 0;
  auto mv = [&](int l, int r) {
    assert(!rod[l].empty());
    k += 1;
    int v = rod[l].back();
    rod[l].pop_back();
    rod[r].emplace_back(v);
    f[l][v] -= 1;
    f[r][v] += 1;
    ans.emplace_back(l+1,r+1);
    dbg(rod);
  };
  while (true) {
    while (!rod[0].empty() && (rod[2].empty() || rod[2].back() > rod[0].back())) {
      mv(0,2);
    }
    if ((int)rod[2].size() == n) {
      break;
    }
    assert(!rod[0].empty());
    mv(0,1);
    while (!rod[2].empty() || !rod[1].empty()) {
      if (rod[2].empty()) {
        mv(1,0);
        break;
      }
      if (!rod[1].empty() && rod[1].back() < rod[2].back()) {
        mv(1,0);
      }
      else {
        mv(2,0);
      }
    }
  }
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}





