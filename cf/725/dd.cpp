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

int fact(int n) {
  int ans = 0;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      ans++;
    }
  }
  if (n > 1) {
    ans++;
  }
  return ans;
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  if (a < b) {
    swap(a, b);
  }
  if (k == 1) {
    cout << (a != b && a % b == 0 ? "yes\n" : "no\n");
  }
  else {
    int g = gcd(a, b);
    int x = fact(a / g) + fact(b / g) + 2 * fact(g);
    cout << (x >= k ? "yes\n" : "no\n");
  }
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





