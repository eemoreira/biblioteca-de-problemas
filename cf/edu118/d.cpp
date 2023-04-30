#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int mod = 998244353, MAX = 2e5 + 5;

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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<long long> dp1(n+5), dp2(n+5);
  dp1[0] = 1;
  for (int i = 0; i < n; i++) {
    dp1[a[i]+1] = mul(2, dp1[a[i]+1]); // -> [0 .. a[i]] 
    dp1[a[i]+1] = add(dp1[a[i]], dp1[a[i]+1]); // take from [0 .. a[i]-1] and bring to [0 .. a[i]]
    if (a[i] > 0) {
      dp2[a[i]-1] = mul(2, dp2[a[i]-1]); // [0 .. a[i]-2 .. a[i]]
      dp2[a[i]-1] = add(dp2[a[i]-1], dp1[a[i]-1]); // take from [0 .. a[i]-2] and bring to [0 .. a[i]-2 .. a[i]]
    }
    dp2[a[i]+1] = mul(2, dp2[a[i]+1]); // [0 .. a[i]-2 .. a[i]]
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = add(ans,dp1[i]);
    ans = add(ans, dp2[i]);
  }
  ans = add(ans,-1);
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





