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
auto solve() -> void {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  sort(a.begin(), a.end());
  if (a[0] == 0) {
    cout << min(a[0], 24 - a[0]) << '\n';
    return;
  }
  vector<int> v, f(13);
  for (int i = 0; i < n; i++) {
    f[a[i]]++;
  }
  for (int i = 1; i <= 12; i++) {
    if (f[i] > 2) {
      cout << 0 << '\n';
      return;
    }
    for (int j = 0; j < min(2, f[i]); j++) {
      v.emplace_back(!j ? i : 24 - i);
    }
  }
  v.emplace_back(0);
  f[0]++;
  sort(v.begin(), v.end());
  n = v.size();
  int ans = 0;
  dbg(v);
  for (int i = 0; i < 1 << 13; i++) {
    vector<int> now(n);
    int p = 0;
    for (int j = 0; j < 13; j++) {
      if (!f[j]) {
        continue;
      }
      assert(p < n);
      if (f[j] > 1) {
        now[p] = j;
        p++;
        now[p] = 24 - j;
        p++;
        continue;
      }
      if (i >> j & 1) {
        now[p] = 24 - j;
      }
      else {
        now[p] = j;
      }
      p++;
    }
    int x = 24;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (j == k) {
          continue;
        }
        int y = abs(now[j] - now[k]);
        x = min(x, min(24 - y, y));
      }
    }
    ans = max(ans, x);
  }
  cout << ans << '\n';
}

auto main() -> int32_t {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





