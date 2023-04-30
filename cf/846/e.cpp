#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  long long l,r;
  cin >> l >> r;
  long long ans = max(0LL, r/2-l);
  vector<int> x;
  int last = 1;
  while (last <= l) {
    long long a = last;
    long long b = l;
    int now = (l+last-1)/last;
    int f = -1;
    while (a <= b) {
      long long mid = (a+b)>>1;
      long long y = (mid + l - 1) / mid;
      if (y < now) {
        b = mid - 1;
      }
      else {
        f = mid;
        a = mid + 1;
      }
    }
    last = f+1;
    x.emplace_back(f);
  }
  dbg(x);
  int d = 0;
  for (auto u : x) {
    int a = d+1;
    int b = u;
    int now = -1;
    while (a <= b) {
      long long mid = (a+b)>>1;
      if (mid * ((l+mid-1)/mid) <= r - mid) {
        now = mid;
        a = mid + 1;
      }
      else {
        b = mid - 1;
      }
    }
    if (~now) {
      ans += (now - d);
    }
    d = u;
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





