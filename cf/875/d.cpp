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

// get divisors of all x for x in [1, 2n]
// do stuff

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[a[i]].emplace_back(i);
  }
  vector<unordered_map<int,int>> f(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto u : pos[i]) {
      f[i][b[u]]++;
    }
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans -= (1LL * a[i] * a[i] == 2LL * b[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 1; x <= n && x*i <= 2 * n; x++) {
      int l = i;
      int r = x;
      if (pos[l].size() > pos[r].size()) {
        swap(l, r);
      }
      for (auto &[val, freq] : f[l]) {
        if (f[r].count(l * r - val)) {
          ans += 1LL * freq * f[r][r*l - val];
        }
      }
    }
  }
  ans >>= 1;
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





