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
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    p[--v] = i;
  }
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    q[--v] = i;
  }
  long long ans = 1;
  int l = n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int x = min(q[i],p[i]);
    int y = max(q[i],p[i]);
    if (r < l) {
      ans += 1LL * x * (x + 1) / 2;
      long long w = n - y - 1;
      ans += w * (w + 1) / 2;
      w = y - x - 1;
      ans += w * (w + 1) / 2;
    }
    else {
      dbg(i,l,r,x,y);
      if (x >= l && x <= r) {
        l = min({l, q[i], p[i]});
        r = max({r, q[i], p[i]});
        continue;
      }
      if (y >= l && y <= r) {
        l = min({l, q[i], p[i]});
        r = max({r, q[i], p[i]});
        continue;
      }
      if (x < l && y < l) {
        ans += 1LL * (r - y - (r - l)) * (n - r);
      }
      else if (x > r && y > l) {
        ans += 1LL * (x - l - (r - l)) * (l + 1);
      }
      else {
        assert(x < l && y > r);
        dbg(l,r,x,y);
        ans += 1LL * (l - x) * (y - r);
      }
    }
    dbg(l,r,ans);
    l = min({l, q[i], p[i]});
    r = max({r, q[i], p[i]});
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





