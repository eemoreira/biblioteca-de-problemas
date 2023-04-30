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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> c(k + 1, vector<int>(2));
  for (int i = 1; i <= k; i++) {
    cin >> c[i][0];
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i][1];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1e18));
  dp[0][0] = 0;
  long long ans = 1e18;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int v = max(i,j);
      v += 1;
      if (v > n) {
        continue;
      }
      dp[i][v] = min(dp[i][v], dp[i][j] + (a[j] == a[v] ? c[a[v]][1] : c[a[v]][0]));
      dp[v][j] = min(dp[v][j], dp[i][j] + (a[i] == a[v] ? c[a[v]][1] : c[a[v]][0]));
      if (v == n) {
        ans = min(ans, dp[i][v]);
      }
    }
  }
  cout << ans << '\n';
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






