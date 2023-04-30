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
  vector<string> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<long long>> dp(n, vector<long long>(n));
  const int mod = 1e9 + 7;
  dp[0][0] = a[0][0] == '.';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*') {
        continue;
      }
      if (i > 0 && a[i-1][j] == '.') {
        dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
      }
      if (j > 0 && a[i][j-1] == '.') {
        dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
      }
    }
  }
  cout << dp[n-1][n-1] << '\n';
}





