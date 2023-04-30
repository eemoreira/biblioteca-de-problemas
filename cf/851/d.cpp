#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mod = 1e9+7, MAX = 2e5 + 5;
/* const int mod = 998244353, MAX = 2e5 + 5; */
long long f[MAX];

inline long long add(long long a, long long b){
  long long ans = a + b;
  ans %= mod;
  if(ans < 0) ans += mod;
  return ans;
}
inline long long mul(long long a, long long b){
  long long ans = a * b % mod;
  if (ans < 0) ans += mod;
  ans %= mod;
  return ans;
}
inline long long bpw(long long a, long long e){
  long long ans = 1;
  while(e){
    if(e&1){
      ans = ans * a % mod;
    }
    a = a * a % mod;
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  auto lb = [&](int i, int j) {
    if (i == 0) return -1;
    int l = 0;
    int r = i-1;
    int d = a[j] - a[i];
    int ret = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[i] - a[mid] > d) {
        ret = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    return ret;
  };
  auto up = [&](int i, int j) {
    if (j == n-1) return n;
    int l = j+1;
    int r = n-1;
    int d = a[j] - a[i];
    int ret = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] - a[j] >= d) {
        ret = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    return ret;
  };
  long long ans = 0;
  vector<long long> p(n << 1);
  p[0] = 1;
  for (int i = 1; i < n << 1; i++) {
    p[i] = p[i-1] * 2 % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int l = lb(i,j)+1;
      int r = up(i,j)-1;
      ans = ans + p[l + n - 1 - r];
      ans %= mod;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





