#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n,m;
  cin >> n >> m;
  if (m < n) {
    cout << 0 << '\n';
    return;
  }
  long long mx = 4LL << __lg(m);
  mx -= 1;
  mx -= n;
  dbg(mx);
  for (int i = 33; i >= 0; i--) {
    long long now = 1LL << i;
    dbg(mx, now);
    long long v = (mx - now) ^ n;
    if ((mx & now) && v > m) {
      mx -= now;
    }
  }
  cout << mx << '\n';
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





