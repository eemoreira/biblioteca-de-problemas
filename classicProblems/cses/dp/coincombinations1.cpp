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
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int mod = 1e9 + 7;
  vector<long long> dp(x+1);
  dp[0] = 1;
  for (int i = 0; i <= x; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= a[j]) {
        dp[i] = (dp[i] + dp[i - a[j]]) % mod;
      }
    }
  }
  cout << dp[x] << '\n';
}





