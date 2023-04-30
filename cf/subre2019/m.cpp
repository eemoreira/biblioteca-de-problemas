#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, c, t;
  cin >> n >> c >> t;
  vector<int> a(n);
  int mx = 0;
  for (auto &u : a) {
    cin >> u;
  }
  auto check = [&](int x) {
    int ptr = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
      if (ptr >= c) {
        return false;
      }
      if (y + a[i] <= x) {
        y += a[i];
      }
      else {
        if (y == 0) return false;
        ptr += 1;
        y = 0;
        --i;
      }
    }
    return true;
  };
  int l = 0, r = 1e9;
  int ans = 1e9;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid  + 1;
    }
  }
  cout << (ans + t - 1) / t << '\n';
}
