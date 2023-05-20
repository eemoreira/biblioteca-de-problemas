#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int n, m;
vector<ii> mv = {{1,0},{-1,0},{0,1},{0,-1}};
int ans[55][55];

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      ans[i][j] = 1e9;
    }
  }
  multiset<i3> pq; 
  pq.emplace(0,0,0);
  ans[0][0] = 0;
  while (!pq.empty()) {
    auto [i, j, op] = *pq.begin();
    pq.erase(pq.begin());
    if (ans[i][j] < op) {
      continue;
    }
    ans[i][j] = min(ans[i][j], op);
    for (auto [x, y] : mv) {
      int ix = i + x;
      int jy = j + y;
      if (valid(ix, jy)) {
        int now = (a[i][j] + op) % 10;
        int going = (a[ix][jy] + op) % 10;
        if (going <= now + 1 && op + 1 < ans[ix][jy]) {
          ans[ix][jy] = op + 1;
          pq.emplace(ix, jy, op + 1);
        }
        else if (op + 10 - going + 1 < ans[ix][jy]) {
          ans[ix][jy] = op + 10 - going + 1;
          pq.emplace(ix, jy, op + 10 - going + 1);
        }
      }
    }
  }
  cout << ans[n - 1][m - 1] << '\n';
}






