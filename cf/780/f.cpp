#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ps(n + 1), pm(n + 1);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i-1] + (s[i-1] == '+');
    pm[i] = pm[i-1] + (s[i-1] == '-');
  }
  dbg(ps, pm);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      int x = ps[j] - ps[i-1];
      int y = pm[j] - pm[i-1];
      if (x > y) {
        continue;
      }
      y -= x;
      if (y % 3 == 0) {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





