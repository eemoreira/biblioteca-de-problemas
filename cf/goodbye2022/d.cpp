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

template<typename T = int, T mod = 1000000007, typename U = long long>
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
using mint = umod<int, MODD, ll>;
ostream& operator << (ostream& os, mint oth) {
    os << oth.val; return os;
}

class dsu {
public:
    vector<int> p;
    int n;
    vector<int> sz, e;
    dsu(int _n) : n(_n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
        e.assign(n, 0);
    }
    inline int find(int x){
        return x == p[x] ? x : (p[x] = find(p[x]));
    }
    inline bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if (sz[y] < sz[x]) swap(y, x);
        if(x != y){
            p[x] = y;
            sz[y] += sz[x];
            e[y] += e[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &u : a) {
    cin >> u;
    --u;
  }
  for (auto &u : b) {
    cin >> u;
    --u;
  }
  dsu d(n);
  for (int i = 0; i < n; i++) {
    d.unite(a[i], b[i]);
    d.e[d.find(a[i])]++;
  }
  vector<int> good(n);
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      good[d.find(a[i])] = 1;
    }
  }
  mint ans = 1;
  for (int i = 0; i < n; i++) {
    if (d.find(i) == i) {
      if (d.sz[i] == d.e[i]) {
        ans *= mint(good[i] ? n : 2);
      }
      else {
        cout << 0 << '\n';
        return;
      }
    }
  }
  cout << ans << '\n';
}

auto main() -> int {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





