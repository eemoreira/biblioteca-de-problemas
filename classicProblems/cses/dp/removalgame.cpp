#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MAX = 5e3 + 5;
int n;
long long dp[MAX][MAX];
long long a[MAX];

long long go(int i, int j) {
  if (j < i) {
    return 0;
  }
  if (i == j) {
    return a[i];
  }
  if (~dp[i][j]) {
    return dp[i][j];
  }
  long long l = go(i+2,j) + a[i];
  long long r = go(i+1,j-1) + a[i];
  long long h = go(i+1,j-1) + a[j];
  long long w = go(i,j-2) + a[j];
  return dp[i][j] = max(min(l,r),min(h,w));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }
  cout << go(0,n-1) << '\n';
}





