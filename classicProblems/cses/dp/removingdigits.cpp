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
  int n;
  cin >> n;
  vector<int> dp(n+1, 1e9);
  dp[n] = 0;
  for (int i = n; i >= 0; i--) {
    if (dp[i] == 1e9){
      continue;
    }
    int t = i;
    while (t) {
      int d = t % 10;
      dp[i - d] = min(dp[i] + 1, dp[i - d]);
      t /= 10;
    }
  }
  cout << dp[0] << '\n';
}





