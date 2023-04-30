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
const int N = 1e6 + 5;
long long a[N], b[N], c[N], d[N];

void solve() {
  long long n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  int j = 0;
  for (int i = 0; i < n; i++) {
    j += s[i] != t[i];
  }
  if (j == 0) {
    cout << 0 << '\n';
    return;
  }
  a[0] = 0;
  b[0] = 0;
  c[n] = 1;
  d[n] = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = dv(add(n, mul(i, a[i-1])), add(n, -mul(i,b[i-1])));
    b[i] = dv(add(n,-i), add(n, -mul(i, b[i-1])));
  }
  for (int i = n-1; i >= 0; i--) {
    c[i] = dv(add(n,mul(c[i+1],add(n,-i))), add(n, -mul(add(n,-i),d[i+1])));
    d[i] = dv(i, add(n, -mul(add(n,-i), d[i+1])));
  }
  cout << dv(add(c[j], mul(d[j], a[j-1])),add(1, -mul(d[j],b[j-1]))) << '\n';
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





