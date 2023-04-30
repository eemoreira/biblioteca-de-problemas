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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  int ans = 0;
  int sobra = 0;
  int y = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      y += 1;
      if (!sobra) {
        ans += 1;
      }
      else {
        sobra -= 1;
        cnt += 1;
      }
    }
    else if (y > 0) {
      sobra = y - y/2 - 1 - cnt;
      dbg(y, sobra);
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





