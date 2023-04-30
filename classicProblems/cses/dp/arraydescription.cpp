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
  int n,x;
  cin >> n >> x;
  vector<int> a(n+2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int mod = 1e9 + 7;
  vector<vector<long long>> dp(n+1, vector<long long>(x+1));
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      if (i == 1) {
        dp[i][a[i]] = 1;
      }
      else {
        for (int j = -1; j <= 1; j++) {
          if (a[i] + j >= 1 && a[i] + j <= x) {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i] + j]) % mod;
          }
        }
      }
      continue;
    }
    int l = a[i-1];
    if (l == 0) {
      if (i == 1) {
        dp[i] = vector<long long>(x+1,1);
        continue;
      }
      for (int j = 1; j <= x; j++) {
        for (int d = -1; d <= 1; d++) {
          if (j + d >= 1 && j + d <= x) {
            dp[i][j] = (dp[i-1][j + d] + dp[i][j]) % mod;
          }
        }
      }
    }
    else {
      for (int j = -1; j <= 1; j++) {
        if (l + j >= 1 && l + j <= x) {
          dp[i][l + j] = (dp[i][l + j] + dp[i-1][l]) % mod;
        }
      }
    }
  }
  long long ans = 0;
  dbg(dp);
  for (int i = 1; i <= x; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << '\n';
}





