#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int mod = 998244353, MAX = 2e5 + 5;
long long f[MAX];

long long add(long long a, long long b){
  long long ans = (a%mod + b%mod + mod)%mod;
  if(ans < 0) ans += mod;
  return ans;
}
long long mul(long long a, long long b){
  long long ans = (a%mod * b%mod)%mod;
  if(ans < 0) ans += mod;
  return ans;
}
long long bpw(long long a, long long e){
  long long ans = 1;
  while(e){
    if(e&1){
      ans = mul(ans,a);
    }
    a = mul(a,a);
    e >>= 1;
  }
  return ans;
}
long long invMod(long long a){
  return bpw(a, mod-2)%mod;
}
long long dv(long long a, long long b){
  return mul(a, invMod(b));
}
long long nCr(int n, int r) {
  if(r > n) return -1;
  return dv(f[n], mul(f[n-r], f[r]));
}
const int N = 350;
const int mx = 1e5 + 5;
int dp[N][2*mx];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*mx; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][mx] = 1;
  for (int i = 1; i < n-1; i++) {
    for (int j = 0; j < 2*mx; j++) {
      if (dp[i-1][j] == 0) continue;
      dp[i][j+a[i]] = add(dp[i][j+a[i]], dp[i-1][j]);
      if (j + a[i] != mx) {
        dp[i][2*mx-j-a[i]] = add(dp[i][2*mx-j-a[i]],dp[i-1][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 2*mx; i++) {
    ans = add(ans, dp[n-2][i]);
  }
  cout << ans << '\n';
}







