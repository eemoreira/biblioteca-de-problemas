#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int N = 1e6 + 5;
int MAX;

const int mod = 998244353;
long long f[N];

inline long long add(long long a, long long b){
  long long ans = (a + b) % mod;
  if(ans < 0) ans += mod;
  return ans;
}
inline long long mul(long long a, long long b){
  long long ans = a * b % mod;
  if (ans < 0) ans += mod;
  return ans;
}
inline long long bpw(long long a, long long e){
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
inline long long invMod(long long a){
  return bpw(a, mod-2);
}
inline long long dv(long long a, long long b){
  return mul(a, invMod(b));
}
inline long long nCr(int n, int r) {
  if(r > n) return 0;
  return dv(f[n], mul(f[n-r], f[r]));
}

int l,r,mx;
long long bs(int k) {
  int p = 1;
  for (int i = 1; i <= mx - 1 - k; i++) {
    p *= 3;
  }
  int L = l, R = MAX;
  long long ans = 0;
  while (L <= R) {
    long long mid = (L + R) >> 1;
    long long v = mid << k;
    v *= p;
    if (v <= r) {
      ans = mid - l + 1;
      L = mid + 1;
    }
    else {
      R = mid - 1;
    }
  }
  return ans * nCr(mx-1,mx-1-k) % mod;
}

void solve() {
  cin >> l >> r;
  mx =  1;
  int y = l;
  int g = l;
  MAX = l;
  while (g*2 <= r) {
    g <<= 1;
    mx += 1;
  }
  cout << mx << ' ';
  int t = mx - 1;
  vector<int> a;
  bool ok = true;
  int x = r;
  while (y <= x) {
    int mid = (y + x) >> 1;
    if ((mid << t) <= r) {
      y = mid + 1;
      MAX = mid;
    }
    else {
      x = mid - 1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < mx; i++) {
    ans = (ans + bs(i)) % mod;
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i-1] * i % mod;
  }
  while (tt--) {
    solve();
  }
}





