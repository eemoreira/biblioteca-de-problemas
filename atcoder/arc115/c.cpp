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
  int n;
  cin >> n;
  vector<int> ans(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j+=i) {
      ans[j] = max(ans[j], ans[i] + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}





