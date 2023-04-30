#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
string s,t;
int n,m;
const int MAX = 5e3 + 5;
int dp[MAX][MAX];

int go(int i, int j) {
  if (i == n) {
    return m - j;
  }
  if (j == m) {
    return n - i;
  }
  if (~dp[i][j]) {
    return dp[i][j];
  }
  int l = go(i,j+1) + 1;
  int r = go(i+1,j) + 1;
  int h = go(i+1,j+1) + (s[i] != t[j]);
  return dp[i][j] = min({l,r,h});
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = -1;
    }
  }
  cout << go(0,0) << '\n';
}





