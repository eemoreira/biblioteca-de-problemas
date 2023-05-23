#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

template<typename T = int, T mod = 1'000'000'007, typename U = long long>
struct umod {
  U val;
  umod(): val(0){};
  umod(U x){ x %= mod; if(x < 0) x += mod; val = x; }
  umod& operator += (umod oth){ val += oth.val; if(val >= mod) val -= mod; return *this; }
  umod& operator -= (umod oth){ val -= oth.val; if(val < 0) val += mod; return *this; }
  umod& operator *= (umod oth){ val = ((U)val) * oth.val % mod; return *this; }
  umod& operator /= (umod oth){ return *this *= oth.inverse(); }
  umod& operator ^= (U oth){ return *this = pwr(*this, oth); }
  umod operator + (umod oth) const { return umod(*this) += oth; }
  umod operator - (umod oth) const { return umod(*this) -= oth; }
  umod operator * (umod oth) const { return umod(*this) *= oth; }
  umod operator / (umod oth) const { return umod(*this) /= oth; }
  umod operator ^ (long long oth) const { return umod(*this) ^= oth; }
  bool operator < (umod oth) const { return val < oth.val; }
  bool operator > (umod oth) const { return val > oth.val; }
  bool operator <= (umod oth) const { return val <= oth.val; }
  bool operator >= (umod oth) const { return val >= oth.val; }
  bool operator == (umod oth) const { return val == oth.val; }
  bool operator != (umod oth) const { return val != oth.val; }
  umod pwr(umod a, U b) const { umod r = 1; for(; b; a*=a, b >>= 1) if(b&1) r *= a; return r; }
  umod inverse() const {
    U a = val, b = mod, u = 1, v = 0;
    while(b){
      U t = a/b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    if(u < 0) u += mod;
    return u;
  }
};
 
const int MODD = 998244353;
using mint = umod<int, MODD, ll>;
ostream& operator << (ostream& os, mint oth) {
  os << oth.val; return os;
}

mint ncr(ll n, ll r) {
  if (r < 0 || n < 0 || r > n) {
    return mint(0);
  }
  mint num = 1;
  mint den = 1;
  for (ll i = 0; i < r; i++) {
    num *= mint(n - i);
  }
  for (ll i = 1; i <= r; i++) {
    den *= mint(i);
  }
  return num / den;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  if (m % k) {
    cout << 0 << '\n';
    return 0;
  }
  ll q = m / k;
  mint ans = 0;
  for (ll i = 0; i <= n - k + 1; i++) {
    mint op1 = ncr(n - k + 1, i) * (i & 1 ? -1 : 1);
    mint op2 = ncr(2 * n - k + q - i * k, 2 * n - k);
    dbg(op1.val, op2.val);
    ans += op1 * op2;
  }
  cout << ans << '\n';
}





