#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* stop freaking out pls */

const int mod = 1e9+7, mx = 2e5 + 5;
long long f[mx];

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
  if(r > n) return 0;
  return dv(f[n], mul(f[n-r], f[r]));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  f[0] = 1;
  for (int i = 1; i < mx; i++) {
    f[i] = mul(f[i-1],i);
  }
  long long n,p;
  cin >> n >> p;
  vector<long long> a(n);
  set<long long, greater<long long>> s;
  for (auto &u : a) {
    cin >> u;
    s.emplace(u);
  }
  dbg(s);
  for (int i = 0; i < n; i++) {
    long long t = a[i];
    if (__lg(a[i]) >= p) {
      s.erase(a[i]);
      continue;
    }
    while (t) {
      if (t != a[i] && s.find(t) != s.end()) {
        s.erase(a[i]);
        break;
      }
      if (t&1) {
        t >>= 1;
      }
      else if (t%4==0) {
        t >>= 2;
      }
      else {
        break;
      }
    }
  }
  dbg(s);
  vector<long long> dp(p), amt(p);
  for (auto u : s) {
    amt[__lg(u)]++;
  }
  dp[0] = amt[0];
  if (p > 1) {
    dp[1] = add(dp[0], amt[1]);
  }
  for (int i = 2; i < p; i++) {
    dp[i] = add(amt[i], add(dp[i-1],dp[i-2]));
  }
  long long ans = 0;
  for (int i = 0; i < p; i++) {
    ans = add(ans, dp[i]);
  }
  cout << ans << '\n';
}



