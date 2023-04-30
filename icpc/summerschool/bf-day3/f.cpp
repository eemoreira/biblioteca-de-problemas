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
void solve() {
  int n;
  cin >> n;
  vector<vector<long long>> g(n);
  for (int i = 0; i < n; i++) {
    int l,r;
    cin >> l >> r;
    g[i].emplace_back(l);
    g[i].emplace_back(r);
  }
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector<vector<long long>> dp(n, vector<long long>(2));
  function<void(int,int)> Dfs = [&](int v, int p) {
    for (auto u : adj[v]) {
      if (u != p) {
        Dfs(u,v);
        for (int i = 0; i < 2; i++) {
          long long ch = 0;
          for (int j = 0; j < 2; j++) {
            ch = max(ch, dp[u][j] + abs(g[u][j] - g[v][i]));
          }
          dp[v][i] += ch;
        }
      }
    }
  };
  Dfs(0,0);
  long long ans = 0;
  dbg(dp);
  cout << max(dp[0][1], dp[0][0]) << '\n';
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




