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
  int n, A;
  cin >> n >> A;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x = A * n;
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(x + 1)));
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int o = 1; o <= i; o++) {
      for (int j = 0; j <= x; j++) {
        if (j >= a[i]) {
          dp[i][o][j] += dp[i-1][o - 1][j - a[i]];
        }
        dp[i][o-1][j] += dp[i-1][o-1][j];
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i][A * i];
  }
  cout << ans << '\n';
}





