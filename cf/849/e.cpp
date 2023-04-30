#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<long long>> dp(n, vector<long long>(2,-1e18));
  dp[0][0] = a[0];
  dp[0][1] = -a[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j] = max(dp[i][j], dp[i-1][k] + (k != j ? -a[i] : a[i]));
      }
    }
  }
  dbg(dp);
  cout << dp[n-1][0]  << '\n';
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





