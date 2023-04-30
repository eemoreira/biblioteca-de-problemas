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
  cin >> n >> k;
  vector<long long> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> dp(n+1, vector<long long>(32, -1e18));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < min(i+1, 32); j++) {
      if (j == 31) {
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
      }
      dp[i][j] = max(dp[i-1][j] - k + (a[i] >> j) , dp[i][j]);
      if (j > 0) {
        dp[i][j] = max(dp[i-1][j-1] + (a[i] >> j), dp[i][j]);
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





