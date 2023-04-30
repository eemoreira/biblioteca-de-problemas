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

void solve() {
  long long n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  int j = 0;
  for (int i = 0; i < n; i++) {
    j += s[i] != t[i];
  }
  vector<long long> dp(n+1);
  dp[1] = bpw(2,n)-1;
  for (long long i = 2; i < n; i++) { 
    long long d = dv(i-1,n);
    long long x = add(dp[i-1], add(-1, -mul(d, dp[i-2])));
    long long y = dv(n, n-i+1);
    dp[i] = mul(x,y);
  }
  dp[n] = add(1,dp[n-1]);
  cout << dp[j] << '\n';
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




