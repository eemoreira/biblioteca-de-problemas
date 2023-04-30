#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  int n,k;
  long long x;
  cin >> n >> k >> x;
  vector<int> a(n + 1);
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1,-1e18));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= min(i,k); j++) {
      if (j > 0) {
        if (dp[i-1][j-1] != -1e18) {
          dp[i][j] = max(dp[i-1][j-1] + a[i] + x, a[i] + x);
        }
        if (dp[i-1][j] != -1e18) {
          dp[i][j] = max({dp[i][j],dp[i-1][j] + a[i] - x, a[i] - x});
        }
      }
      else {
        if (dp[i-1][j] != -1e18) {
          dp[i][j] = max(dp[i-1][j] + a[i] - x, a[i] - x);
        }
      }
    }
  }
  dbg(dp);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i,k); j++) {
      if (n - i >= k - j) {
        ans = max(dp[i][j], ans);
      }
    }
  }
  cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





