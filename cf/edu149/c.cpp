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
  string s;
  cin >> s;
  int n = s.size();
  auto good = [&](char c) {
    return c == '?' || c == '1';
  };
  string ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      while (i < n && s[i] == '?') {
        ans += '0';
        i++;
      }
    }
    while (i < n && good(s[i])) {
      ans += '1';
      i++;
    }
    if (i < n) {
      ans += '0';
    }
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





