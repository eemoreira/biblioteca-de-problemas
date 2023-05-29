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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  int x = 0;
  map<int,int> f;
  f[0]++;
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    x += a[i];
    ans += f[x - k];
    f[x]++;
  }
  cout << ans << '\n';
}





