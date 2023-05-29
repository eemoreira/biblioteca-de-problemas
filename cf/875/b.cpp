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
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  vector<int> besta(2 * n + 1), bestb(2 * n + 1);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int x = a[i];
    while (i < n && a[i] == x) {
      i++;
      cnt++;
    }
    i--;
    besta[x] = max(cnt, besta[x]);
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int x = b[i];
    while (i < n && b[i] == x) {
      i++;
      cnt++;
    }
    i--;
    bestb[x] = max(cnt, bestb[x]);
  }
  int ans = 1;
  for (int i = 0; i <= 2 * n; i++) {
    ans = max(ans, besta[i] + bestb[i]);
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





