#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

template<typename T = int, T mod = 1'000'000'007, typename U = long long>
struct umod {
    T val;
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
using mint = umod<int, MODD, i64>;
ostream& operator << (ostream& os, mint oth) {
    os << oth.val; return os;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (auto &u : a) {
    cin >> u;
  }

  mint ans = 1;

  for (int o = 0; o < n; o++) {
    vector<int> new_a;
    int k = a.size();
    i64 losers = 0;
    dbg(k, a);
    for (int i = 0; i < k; i+=2) {
      if (a[i] == a[i + 1] && a[i] == -1) {
        ans *= 2;
        new_a.emplace_back(-1);
        ans *= mint(++losers);
      }
      else if (a[i] != -1 && a[i + 1] != -1) {
        if ((a[i] <=  k / 2) == (a[i + 1] <= k / 2)) {
          cout << 0 << '\n';
          return 0;
        }
        else {
          new_a.emplace_back(min(a[i], a[i + 1]));
        }
      }
      else {
        if (a[i] == -1) {
          swap(a[i], a[i + 1]);
        }
        if (a[i] <= k / 2) {
          new_a.emplace_back(a[i]);
          ans *= mint(++losers);
        }
        else {
          new_a.emplace_back(-1);
        }
      }
    }
    swap(a, new_a);
  }
  cout << ans << '\n';
}





