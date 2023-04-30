#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mx = 105;
const int mxx = 1 << 10 | 16;
int dp[mx][mx][mxx];
int a[mx][mx];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int lx,ly,rx,ry;
  cin >> lx >> ly >> rx >> ry;
  --lx; --ly; --rx; --ry;
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cin >> a[i][j];
          a[i][j]--;
          a[i][j] = 1 << a[i][j];
      }
  }
  vector<pair<int,int>> mv = {{1,0}, {0,1}, {-1,0}, {0,-1}};
  auto valid = [&](int x, int y) {
      return x >= 0 && y >= 0 && x < n && y < m;
  };
  queue<pair<pair<int,int>,int>> q;
  q.emplace(make_pair(lx,ly), a[lx][ly]);
  while (!q.empty()) {
      auto now = q.front();
      q.pop();
      int v = now.first.first;
      int u = now.first.second;
      int mask = now.second;
      if (dp[v][u][mask]) {
          continue;
      }
      dp[v][u][mask] = 1;
      for (auto [x,y] : mv) {
          if (valid(v+x,u+y)) {
              q.emplace(make_pair(v+x,u+y), mask | a[v+x][u+y]);
          }
      }
  }
  int ans = 1e9;
  for (int i = 0; i < 1 << 10; i++) {
      if (dp[rx][ry][i]) {
          ans = min(ans,__builtin_popcount(i));
      }
  }
  cout << ans << '\n';
}







