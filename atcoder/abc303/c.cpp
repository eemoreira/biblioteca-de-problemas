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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, h, k;
  cin >> n >> m >> h >> k;
  string s;
  cin >> s;
  int x = 0, y = 0;
  map<ii, int> f;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    f[ii(l, r)]++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      x++;
    }
    if (s[i] == 'L') {
      x--;
    }
    if (s[i] == 'U') {
      y++;
    }
    if (s[i] == 'D') {
      y--;
    }
    h--;
    dbg(h, x, y, f);
    if (h < 0) {
      cout << "No\n";
      return 0;
    }
    if (h < k && f[ii(x,y)]) {
      h = k;
      f[ii(x,y)] = 0;
    }
  }
  cout << "Yes\n";
}





