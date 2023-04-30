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
  vector<long long> dp(n+1);
  const int mod = 1e9 + 7;
  for (int i = 1; i <= n; i++) {
    if (i <= 6) {
      dp[i] = 1;
    }
    for (int j = 1; j <= 6; j++) {
      if (i > j) {
        dp[i] = (dp[i] + dp[i-j]) % mod;
      }
    }
  }
  cout << dp[n] << '\n';
}





