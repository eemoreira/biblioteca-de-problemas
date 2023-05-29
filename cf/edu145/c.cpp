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

vector<int> ans;
void go(int n, int k) {
  if (n == 0) {
    return;
  }
  if (k < n) {
    ans = vector<int> (n, -1);
    if (k) {
      ans[k - 1] = 100;
    }
    ans[k] = -200;
  }
  else {
    go(n - 1, k - n);
    ans.emplace_back(1000);
  }
}

auto solve() -> void {
  int n, k;
  cin >> n >> k;
  ans.clear();
  go(n, k);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

auto main() -> int32_t {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





