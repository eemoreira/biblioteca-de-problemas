#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
long long f[MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  f[0] = 1;
  for (int i = 1; i < MAX; i++) {
    f[i] = f[i-1] * i % mod;
  }
  auto inv = [&](long long a) {
    long long ans = 1;
    int e = mod - 2;
    while (e) {
      if (e & 1) {
        ans = ans * a % mod;
      }
      a = a * a % mod;
      e >>= 1;
    }
    return ans;
  };
  auto nCr = [&](long long n, long long r) {
    return f[n] * inv(f[r]) % mod * inv(f[n-r]) % mod;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    vector<long long> p(n+1);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= 2*n; j+=i) {
        p[i] = (p[i] + nCr(n << 1, j)) % mod;
      }
      dp[i] = (dp[i-1] + p[i]) % mod;
    }
    cout << dp[n] << '\n';
  }
}





