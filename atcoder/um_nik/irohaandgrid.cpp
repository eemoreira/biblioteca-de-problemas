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
  const int mod = 1e9 + 7;
  long long h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<long long> f(2 * (h + w + 1));
  f[0] = 1;
  for (int i = 1; i < h + w + 1; i++) {
    f[i] = f[i-1] * i % mod;
  }
  auto bpw = [&](long long x, long long e) {
    long long ret = 1;
    while (e) {
      if (e & 1) {
        ret = ret * x % mod;
      }
      x = x * x % mod;
      e >>= 1;
    }
    return ret
  };
  auto nCr = [&](int n, int r) {
    assert(n >= r);
    assert(r >= 0 && n >= 0 && n < (int)f.size());
    long long v = bpw(f[r] * f[n - r] % mod, mod - 2);
    return f[n] * v % mod;
  };
  long long ans = nCr(w - 1 + h - 1, h - 1);
  for (int i = 0; i < b; i++) {
    int size = i + 1;
    int line = h - a;
    int othsize = w - i;
    int othline = a;
    ans = (ans - nCr(othsize - 1 + othline - 1, othline - 1) * nCr(size - 1 + line - 1, line - 1) % mod) % mod;
    if (ans < 0) ans += mod;
  }
  cout << ans << '\n';
}





