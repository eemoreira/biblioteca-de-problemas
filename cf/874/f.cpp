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
template<typename T, T mod, typename U>
struct Mint {
  U val;
  Mint() : val(0){}
  Mint(U x) {
    x %= mod;
    if (x < 0) {
      x += mod;
    }
    val = x;
  }
  const U Val() {
    return val;
  }
  Mint power(Mint a, ll e) {
    Mint ans = 1;
    for (; e; e >>= 1, a *= a) {
      if (e & 1) {
        ans *= a;
      }
    }
    return ans;
  }
  ll mul(ll a, U b) {
    ll ans = a * b - (1LL * a * b / mod) * mod;
    ans %= mod;
    if (ans < 0) {
      ans += mod;
    }
    return ans;
  }
  const Mint inv() {
    return power(Mint(*this), mod - 2);
  }
  Mint& operator += (Mint rhs) {
    val += rhs.val;
    if (val >= 0) {
      val -= mod;
    }
    if (val < 0) {
      val += mod;
    }
    return *this;
  }
  Mint& operator -= (Mint rhs) {
    val -= rhs.val;
    if (val >= 0) {
      val -= mod;
    }
    if (val < 0) {
      val += mod;
    }
    return *this;
  }
  Mint& operator *= (Mint rhs) {
    val = mul(val, rhs.Val());
    return *this;
  }
  Mint& operator /= (Mint rhs) {
    return *this *= rhs.inv();
  }
  Mint& operator +(Mint rhs) const { 
    return Mint(*this) += rhs;
  }
  Mint& operator -(Mint rhs) const { 
    return Mint(*this) -= rhs;
  }
  Mint& operator *(Mint rhs) const { 
    return Mint(*this) *= rhs;
  }
  Mint& operator /(Mint rhs) const { 
    return Mint(*this) /= rhs;
  }
  bool operator ==(Mint rhs) const {
    return val == rhs.Val();
  }
  bool operator <(Mint rhs) const {
    return val < rhs.Val();
  }
  bool operator <=(Mint rhs) const {
    return val <= rhs.Val();
  }
  bool operator >(Mint rhs) const {
    return val > rhs.Val();
  }
  bool operator >=(Mint rhs) const {
    return val >= rhs.Val();
  }
  bool operator != (Mint rhs) const {
    return val != rhs.Val();
  }
  friend istream& operator >>(istream& in, Mint& a) {
    U v;
    in >> v;
    a = Mint(v);
    return in;
  }
  friend ostream& operator <<(ostream& out, Mint& a) {
    return out << a.Val();
  }
};

const int MODD = 1e9 + 7;
using mint = Mint<int, MODD, ll>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int,int> f;
  for (auto &u : a) {
    cin >> u;
    f[u]++;
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  int ptr = 0;
  mint ans = 0;
  mint x = 1;
  for (int i = 0; i < n; i++) {
    while (ptr < n && a[i] + m > a[ptr]) {
      x *= f[a[ptr]];
      ptr++;
    }
    if (ptr - i == m) {
      ans += x;
    }
    x /= f[a[i]];
  }
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





