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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  if (count(a.begin(), a.end(), 1) != 1) {
    cout << "no\n";
  }
  else {
    if (n == 1) {
      cout << "yes\n";
      return;
    }
    int p = find(a.begin(), a.end(), 1) - a.begin();
    int x = 1;
    for (int i = (p + 1) % n; i != p; (i += 1) %= n) {
      int now = a[i];
      int prev = a[(i + n - 1) % n];
      if (now >= prev) {
        if (now - prev > 1) {
          cout << "no\n";
          return;
        }
        x++;
      }
      else {
        if (prev - now > x) {
          cout << "no\n";
          return;
        }
        x = now;
      }
    }
    cout << "yes\n";
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





