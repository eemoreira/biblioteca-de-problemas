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
  int n, m;
  cin >> n >> m;
  if (m < n) {
    cout << 0 << '\n';
    return;
  }
  int now = 0;
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    now ^= 1 << i;
    /* dbg(ans, ans & (~n)); */
    if (1LL * (now & (~n)) + n > m) {
      ans = n ^ ((now & (~n)) + n);
      now ^= 1 << i;
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





