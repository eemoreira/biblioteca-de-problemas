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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  const int big = sqrt(2 * n) + 5;
  vector<vector<int>> f(big, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    if (a[i] < big) {
      f[a[i]][b[i]]++;
    }
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    i64 val = 1LL * a[i] * a[i] - b[i];
    if (a[i] < big && val > 0 && val <= n) {
      ans += f[a[i]][a[i] * a[i] - b[i]];
    }
  }
  for (int i = 2; i*i <= 2*n; i+=2) {
    ans -= f[i][i * i / 2];
  }
  ans >>= 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < a[i] && j * a[i] <= 2 * n; j++) {
      i64 val = 1LL * j * a[i] - b[i];
      if (val > 0 && val <= n) {
        ans += f[j][a[i] * j - b[i]];
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





