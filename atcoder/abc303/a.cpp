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
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      s[i] = '0';
    }
    if (s[i] == 'l') {
      s[i] = '1';
    }
    if (t[i] == 'o') {
      t[i] = '0';
    }
    if (t[i] == 'l') {
      t[i] = '1';
    }
  }
  cout << (s == t ? "Yes\n" : "No\n");
}





