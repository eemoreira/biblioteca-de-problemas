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
  vector<int> w(n+1),v(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(x+1, -1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      if (w[i] <= j && dp[i-1][j - w[i]] != -1e9) {
        dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}





