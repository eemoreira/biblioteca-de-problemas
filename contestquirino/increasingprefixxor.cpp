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
  int k = __lg(m) + 1;
  if (n > k) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<i64>> dp(n + 1, vector<i64>(k + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      i64 now = 0;
      for (int d = 0; d < j; d++) {
        now = (now + dp[i - 1][d]) % mod;
      }
      i64 x = 0;
      if (j == k) {
        x = m - (1LL << (j - 1)) + 1;
      }
      else {
        x = 1LL << (j - 1);
      }
      x %= mod;
      dp[i][j] = (dp[i][j] + now * x % mod) % mod;
    }
  }
  dbg(dp);
  i64 ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << '\n';
}





