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
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &u : a) {same
    cin >> u;
  }
  vector<vector<int>> Adj(n);
  for (int i = 1 ; i < n ; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    Adj[u].emplace_back(v);
    Adj[v].emplace_back(u);
  }
  vector<int> cnt = a;
  function<void(int, int)> Dfs = [&](int v, int p) {
    for (auto u : Adj[v]) {
      if (u != p) {
        if (cnt[v] == 1e9) {
          cnt[u] = 1e9;
        }
        else {
          dbg(v,u,a[v]);
          cnt[u] = (a[v] ? cnt[u]+cnt[v] : a[u]);
          if (cnt[u] > m) cnt[u] = 1e9;
        }
        Dfs(u,v);
      }
    }
  };
  Dfs(0,0);
  int ans = 0;
  dbg(cnt);
  for (int i = 1; i < n; i++) {
    if ((int)Adj[i].size() == 1) {
      ans += cnt[i] <= m;
    }
  }
  cout << ans << '\n';
}



