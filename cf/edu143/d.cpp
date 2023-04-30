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
  const int mod = 998244353;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<long long> f(n+1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i-1] * i % mod;
  }
  auto inv = [&](long long d) {
    int e = mod - 2;
    long long ret = 1;
    while (e) {
      if (e & 1) {
        ret = ret * d % mod;
      }
      d = d * d % mod;
      e >>= 1;
    }
    return ret;
  };
  long long ans = f[n/3] * inv(f[n/6]) % mod * inv(f[n/3 - n/6]) % mod;
  for (int i = 0; i < n; i+=3) {
    vector<int> b = {a[i],a[i+1],a[i+2]};
    sort(b.begin(), b.end());
    if (b[0] == b[2]) {
      ans = ans * 3 % mod;
    }
    else if (b[0] == b[1]) {
      ans = ans * 2 % mod;
    }
  }
  cout << ans << '\n';
}





