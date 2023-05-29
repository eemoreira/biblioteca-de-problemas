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
void solve() {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 x, y, z;
  cin >> x >> y >> z;
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<i64>> dp(n + 1, vector<i64>(2, 1e18));
  dp[0][0] = 0;
  dp[0][1] = z;
  for (int i = 1; i <= n; i++) {
    int now = s[i - 1] == 'A';
    dp[i][now] = min(dp[i - 1][now] + x, dp[i - 1][!now] + z + x);
    dp[i][!now] = min(dp[i - 1][now] + z + y, dp[i - 1][!now] + y);
  }
  cout << min(dp[n][0], dp[n][1]) << '\n';
}





