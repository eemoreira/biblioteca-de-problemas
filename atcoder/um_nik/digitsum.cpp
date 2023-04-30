#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,s;
  cin >> n >> s;
  if (s > n) {
    cout << -1 << '\n';;
    return 0;
  }
  if (s == n) {
    cout << s + 1 << '\n';
    return 0;
  }
  auto ds = [&](long long b) {
    long long t = n;
    long long ret = 0;
    while (t) {
      ret += t % b;
      t /= b;
    }
    return ret;
  };
  for (long long i = 2; i*i <= n; i++) {
    if (ds(i) == s) {
      cout << i << '\n';
      return 0;
    }
  }
  long long last = n;
  long long ans = 1e18;
  while (last >= 2) {
    long long l = n / (n / last + 1) + 1;
    long long r = last;
    long long nxt = l;
    long long now = -1;
    if (l < 2) {
      if (ds(2) == s) {
        ans = 2;
      }
      break;
    }
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long w = ds(mid);
      if (w <= s) {
        if (w == s) {
          now = mid;
        }
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    if (~now) {
      ans = min(ans,now);
    }
    last = nxt - 1;
  }
  cout << (ans == 1e18 ? -1 : ans) << '\n';
}





