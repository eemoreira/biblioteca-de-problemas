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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < min(n, i + 4); j++) {
      if (j - i < 2) {
        ans++;
      }
      else {
        dbg(i, j);
        bool good = true;
        for (int k = i + 1; k < j; k++) {
          int MIN = 1e9 + 5;
          int MAX = -1;
          int MIN2 = 1e9 + 5;
          int MAX2 = -1;
          for (int o = i; o < k; o++) {
            MIN = min(a[o], MIN);
            MAX2 = max(a[o], MAX2);
          }
          for (int o = k + 1; o <= j; o++) {
            MAX = max(a[o], MAX);
            MIN2 = min(a[o], MIN2);
          }
          if (a[k] >= MIN && a[k] <= MAX) {
            good = false;
            break;
          }
          if (a[k] <= MAX2 && a[k] >= MIN2) {
            good = false;
            break;
          }
        }
        ans += good;
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





