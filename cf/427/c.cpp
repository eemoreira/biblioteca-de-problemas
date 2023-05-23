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
const int maxn = 105;
vector<int> a[maxn][maxn];
ll p[15][maxn][maxn];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, c;
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    a[x][y].emplace_back(k);
  }
  int mod = c + 1;
  for (int m = 0; m < mod; m++) {
    for (int i = 1; i < maxn; i++) {
      for (int j = 1; j < maxn; j++) {
        p[m][i][j] = p[m][i][j - 1] + p[m][i - 1][j] - p[m][i - 1][j - 1];
        for (auto u : a[i][j]) {
          p[m][i][j] += (u + m) % mod;
        }
      }
    }
  }
  while (q--) {
    int t, x0, y0, x1, y1;
    cin >> t >> x0 >> y0 >> x1 >> y1;
    t = t % mod;
    cout << p[t][x1][y1] - p[t][x0 - 1][y1] - p[t][x1][y0 - 1] + p[t][x0 - 1][y0 - 1] << '\n';
  }
}





