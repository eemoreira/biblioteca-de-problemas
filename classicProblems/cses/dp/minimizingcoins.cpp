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
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(x+1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = min(dp[i-1][j], dp[i][j]);
      if (j >= a[i]) {
        dp[i][j] = min(dp[i][j], dp[i][j - a[i]] + 1);
      }
    }
  }
  dbg(dp);
  cout << (dp[n][x] >= 1e9 ? -1 : dp[n][x]) << '\n';
}





