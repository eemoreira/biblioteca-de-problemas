#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mx = (2 << __lg(5000));
void solve() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(mx,1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][a[i]] = dp[i-1][0];
    for (int x = 0; x < mx; x++) {
      dp[i][a[i] ^ x] = min(dp[i][a[i] ^ x], dp[i-1][x] + 1);
      dp[i][a[i] ^ x] = min(dp[i][a[i] ^ x], dp[i-1][0] + 1);
    }
  }
  cout << dp[n][0] << '\n';
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





