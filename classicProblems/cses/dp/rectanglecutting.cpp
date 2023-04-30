#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int a,b;
const int MAX = 505;
int dp[MAX][MAX];

int go(int i, int j) {
  if (i < 0 || j < 0 || i > a || j > b) {
    return 1e9;
  }
  if (i == j) {
    return 0;
  }
  if (dp[i][j] < 1e9) {
    return dp[i][j];
  }
  for (int x = 1; x <= i/2; x++) {
    dp[i][j] = min(dp[i][j], go(i-x,j) + go(x,j) + 1);
  }
  for (int x = 1; x <= j/2; x++) {
    dp[i][j] = min(dp[i][j], go(i,j-x) + go(i,x) + 1);
  }
  return dp[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      dp[i][j] = 1e9;
    }
  }
  cout << go(a,b) << '\n';
}





