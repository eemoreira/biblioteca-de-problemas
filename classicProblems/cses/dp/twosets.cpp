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
  int s = n * (n + 1) / 2;
  if (s & 1) {
    cout << 0 << '\n';
    return 0;
  }
  s >>= 1;
  vector<vector<long long>> dp(s+1, vector<long long>(n+1));
  const int mod = 1e9 + 7;
  dp[0][0] = 1;
  for (int i = 0; i <= s; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j-1];
      if (i >= j) {
        dp[i][j] = (dp[i-j][j-1] + dp[i][j]) % mod;
      }
    }
  }
  cout << dp[s][n] * (mod + 1) / 2 % mod << '\n';
}





