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

const int MAX = 2e5 + 5;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> adj[MAX];
  for (auto &u: a) {
    cin >> u;
  }
  for (int i = 1; i < n; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  vector<map<int,int>> dp(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 1) {
      ans = 1;
      dp[i][a[i]] = 1;
    }
  }
  function<void(int, int)> Dfs = [&](int v, int p) {
    for (auto u : adj[v]) {
      if (u != p) {
        Dfs(u,v);
        if (gcd(a[v],a[u]) > 1) {
          for (auto x : dp[u]) {
            for (auto y : dp[v]) {
              if (gcd(x.first, y.first) > 1) {
                ans = max(ans, x.second + y.second);
              }
            }
          }
        }
        for (auto x : dp[u]) {
          int g = gcd(x.first,a[v]);
          if (g > 1) {
            dp[v][g] = max(dp[v][g], x.second + 1);
          }
        }
        dbg(u, dp[u]);
      }
    }
  };
  Dfs(0,0);
  dbg(dp);
  cout << ans << '\n';
}




