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
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  i64 ans = -1e18;
  const int N = 1 << (__lg(n) + 1);
  for (i64 i = n; i >= 1; i--) {
    for (i64 j = i - 1; j >= 1; j--) {
      if (i * i - i * j > k * N) {
        break;
      }
      ans = max(ans, i * j - k * (a[i] | a[j]));
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





