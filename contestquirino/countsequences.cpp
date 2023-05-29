#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int mod = 998244353;

void solve() {
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n, m;
  cin >> n >> m;
  vector<vector<i64>> dp(n + 1, vector<i64>(3));
  vector<i64> bal(3);
  for (int i = 0; i < 3; i++) {
    bal[i] = m / 3 + (m % 3 >= i);
  }
  dbg(bal);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j > 1) {
        dp[i][j] = (dp[i - 1][(j + 2) % 3] + dp[i - 1][(j + 1) % 3]) % mod;
      }
      else {
        dp[i][j] = 1;
      }
      dp[i][j] = dp[i][j] * bal[j] % mod;
    }
  }
  dbg(dp);
  i64 ans = 0;
  for (int i = 0; i < 3; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << '\n';
}





