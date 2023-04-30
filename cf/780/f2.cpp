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
  string s;
  cin >> s;
  vector<int> ps(n + 1), pm(n + 1);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i-1] + (s[i-1] == '+');
    pm[i] = pm[i-1] + (s[i-1] == '-');
  }
  vector<vector<long long>> dp(n + 1, vector<long long> (3));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int v = (pm[i] - ps[i]) % 3;
    dbg(v);
    if (v < 0) {
      v += 3;
    }
    for (int j = 0; j < 3; j++) {
      dp[i][(j - v + 3) % 3] += dp[i-1][j];
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





