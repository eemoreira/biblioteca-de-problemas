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
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int MAX = 1000 * (n + 1);
  vector<vector<int>> dp(n+1, vector<int>(MAX));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < MAX; j++) {
      dp[i][j] |= dp[i-1][j];
      if (a[i] <= j) {
        dp[i][j] |= dp[i-1][j - a[i]];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < MAX; i++) {
    ans += dp[n][i];
  }
  cout << ans << '\n';
  for (int i = 1; i < MAX; i++) {
    if (dp[n][i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}





