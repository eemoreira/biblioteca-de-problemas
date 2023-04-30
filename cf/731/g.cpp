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
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> hasinf(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    if (u == v) {
      hasinf[u] = -1;
    }
  }
  vector<int> ans(n);
  function<void(int, int, int)> Dfs = [&](int v, int x) {
    ans[v] = x;
    for (auto u : adj[v]) {
      if (u == v) continue;
      hasinf[u] = hasinf[u];
      Dfs(u,v, hasinf[v] ? -1 : min(2,x+1));
    }
  };
  Dfs(0,0,hasinf[0]);
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




