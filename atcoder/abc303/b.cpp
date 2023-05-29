#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  dbg(a);
  map<ii, int> ans; 
  auto check = [&](int x, int y) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (a[i][j] == x && a[i][j + 1] == y) {
          return false;
        }
        if (a[i][j] == y && a[i][j + 1] == x) {
          return false;
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int mx = max(i, j);
      int mn = min(i, j);
      if (check(mx, mn)) {
        ans[ii(mx,mn)];
      }
    }
  }
  dbg(ans);
  cout << ans.size() << '\n';
}





