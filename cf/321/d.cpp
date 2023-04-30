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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<long long>> g(n, vector<long long>(n));
  for (int i = 0; i < k; i++) {
    int x,y,c;
    cin >> x >> y >> c;
    --x; --y;
    g[x][y] = c;
  }
  vector<vector<long long>> dp(1 << n, vector<long long>(n));
  for (int i = 1; i < 1 << n; i++) {
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) continue;
      for (int d = 0; d < n; d++) {
        if (d == j || !(i >> d & 1)) continue;
        dp[i | 1 << j][j] = max(dp[i][d] + g[d][j], dp[i | 1 << j][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < 1 << n; i++) {
    if (__builtin_popcount(i) == m) {
      long long now = 0;
      long long mx = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          now += a[j];
        }
        mx = max(dp[i][j], mx);
      }
      ans = max(ans, mx + now);
    }
  }
  cout << ans << '\n';
}



