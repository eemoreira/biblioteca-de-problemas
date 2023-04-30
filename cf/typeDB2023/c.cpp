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

void solve(){
  long long n,s;
  cin >> n >> s;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long mnans = 1e18;
  vector<vector<long long>> dp(n, vector<long long>(2, 1e18));
  vector<vector<long long>> g(n);
  for (int i = 0; i < n; i++) {
    long long mn = max(0LL, a[i]-s);
    long long mx = a[i] - mn;
    if (mx < mn) swap(mx,mn);
    g[i].emplace_back(mn);
    g[i].emplace_back(mx);
  }
  for (int i = 0; i < 2; i++) {
    dp[1][i] = a[0] * g[1][i];
  }
  for (int i = 2; i < n-1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j] = min(dp[i][j], dp[i-1][k] + g[i-1][k^1] * g[i][j]);
      }
    }
  }
  long long ans = 1e18;
  for (int i = 0; i < 2; i++) {
    ans = min(ans, dp[n-2][i] + a[n-1] * g[n-2][i^1]);
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



