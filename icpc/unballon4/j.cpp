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
 
const int MODD = 1e9 + 7;
using mint = umod<int, MODD, ll>;
ostream& operator << (ostream& os, mint oth) {
    os << oth.val; return os;
}

struct node {
  int MAX, MIN;
  node(int mx, int mn) : MAX(mx), MIN(mn) {}
  node() {
    MAX = -1e9;
    MIN = 1e9;
  }
};

node comp(node a, node b) {
  return node(max(a.MAX, b.MAX), min(a.MIN, b.MIN));
}


const int maxn = 3e5 + 5;
int p2[maxn];
const int lg = __lg(maxn) + 2;
const node neutral = node();

template<typename T>
struct sparseTable {
  vector<T> sparse[lg];
  int n;
  T query(int l, int r){
    int i = p2[r - l + 1];
    return comp(sparse[i][l], sparse[i][r - (1 << i) + 1]);
  }
  sparseTable(vector<T>& a) {
    n = a.size();
    if (p2[2] == 0) {
      for (int i = 2; i < maxn; i++) {
        p2[i] = p2[i >> 1] + 1;
      }
    }
    for(int i = 0; i < lg; i++){
      sparse[i] = vector<T>(n);
    }
    for(int i = 0; i < n; i++){
      sparse[0][i] = a[i];
    }
    for(int i = 1; i < lg; i++){
      for(int j = 0; j + (1 << i) <= n;  j++){
        sparse[i][j] = comp(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
};


template<typename T>
struct fenwick{
    vector<T> ft;
    int n;
    fenwick(int _n) : n(_n){
        ft.resize(n + 1); // 1 indexed
    }
    T rsq(int i){
        T sum = 0;
        for(; i; i -= (i & -i)){
            sum += ft[i];
        }
        return sum;
    }
    T rsq(int i,int k){
        return rsq(k) - rsq(i-1);
    }
    void update(int i, T v){
        for(; i <= n; i += (i & -i)){
            ft[i] += v;
        }
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, l, r, k;
  cin >> n >> l >> r >> k;
  vector<node> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.emplace_back(x, x);
  }
  sparseTable<node> sparse(a);
  vector<mint> dp(n);
  fenwick<mint> f(n + 5);
  f.update(n + 1, mint(1));
  for (int i = n - 1; i >= 0; i--) {
    int L = i + l - 1;
    int R = min(n - 1, i + r - 1);
    if (L >= n) {
      continue;
    }
    int up = -1;
    while (L <= R) {
      int mid = (L + R) >> 1;
      node now = sparse.query(i, mid);
      int dif = now.MAX - now.MIN;
      if (dif <= k) {
        up = mid;
        L = mid + 1;
      }
      else {
        R = mid - 1;
      }
    }
    if (up >= 0) {
      int idxstart = min(n + 1, i + l + 1);
      int idxend = min(n + 1, up + 2);
      dp[i] = f.rsq(idxstart, idxend);
    }
    f.update(i + 1, dp[i]);
  }
  for (int i = 0; i < n; i++) {
    dbg(i, dp[i].val);
  }
  cout << dp[0] << '\n';
}





