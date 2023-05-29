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
  vector<vector<int>> g(n, vector<int>(n));
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
    mn = min(mn, g[i][0]);
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = g[i][0] - mn;
    b[i] = g[0][i] - a[0];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ok &= g[i][j] == a[i] + b[j];
    }
  }
  if (!ok) {
    cout << "No\n";
  }
  else {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
}





