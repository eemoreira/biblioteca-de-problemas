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

bool dp[105][105 * 2000];

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int all = 0;
  bool bad = false;
  for (auto &u : a) {
    cin >> u;
    all += u;
  }
  dbg(all);
  if (all % 2) {
    cout << 0 << '\n';
  }
  else {
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= all/2; j++) {
        if (j - a[i - 1] >= 0) {
          dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
      }
      for (int j = 0; j <= all/2; j++) {
        dp[i][j] |= dp[i - 1][j];
      }
    }
    if (dp[n][all / 2]) {
      cout << 1 << '\n';
      for (int i = 0; i < __lg(2500); i++) {
        int now = 1 << i;
        for (int j = 0; j < n; j++) {
          if (a[j] % now) {
            cout << j + 1 << '\n';
            return;
          }
        }
      }
    }
    else {
      cout << 0 << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





