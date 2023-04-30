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
int l,n;
vector<int> adj[MAX], d, sz, vis, AdjCentroid;
int up[MAX][30];

void Pre_dfs(int v, int p){
  up[v][0] = p;
  for(int i = 1; i <= l; i++){
    up[v][i] = up[up[v][i-1]][i-1];
  }
  for(auto u : adj[v]){
    if (u != p) {
      d[u] = d[v] + 1;
      Pre_dfs(u,v);
    }
  }
}

int lca(int u, int v){
  if (d[u] < d[v]) {
    swap(u,v);
  }
  int k = d[u] - d[v];
  for (int i = l; ~i; i--) {
    if (k >> i & 1) {
      u = up[u][i];
    }
  }
  if (u == v) return v;
  for (int i = l; ~i; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

void preprocess(int root) {
  d.assign(n,0);
  sz.assign(n,0);
  vis.assign(n,0);
  AdjCentroid.assign(n, -1);
  l =  __lg(n) + 1;
  Pre_dfs(root, root);
}

int Get_dist(int v, int u) {
  return d[v] + d[u] - 2 * d[lca(u,v)];
}

int Dfs(int v, int p) {
  sz[v] = 1;
  for (auto u : adj[v]) {
    if (!vis[u] && u != p) {
      sz[v] += Dfs(u,v);
    }
  }
  return sz[v];
}

int Centroid(int v, int p, int size) {
  for (auto u : adj[v]) {
    if (!vis[u] && u != p && sz[u] > size/2) {
      return Centroid(u,v,size);
    }
  }
  return v;
}
int Decompose(int v) {
  int root = Centroid(v, -1, Dfs(v,-1));
  vis[root] = 1;
  for (auto u : adj[root]) {
    if (!vis[u]) {
      AdjCentroid[Decompose(u)] = root;
    }
  }
  return root;
}

void solve(){
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
    adj[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int v,u;
    cin >> v >> u;
    --v; --u;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  preprocess(0);
  Decompose(0);
  vector<int> dp(n,1e9);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int v = c[i];
    int u = c[i];
    while (~u) {
      ans = min(ans, dp[u] + Get_dist(u, c[i]));
      u = AdjCentroid[u];
    }
    while (~v) {
      dp[v] = min(dp[v], Get_dist(v,c[i]));
      v = AdjCentroid[v];
    }
    if (i) {
      cout << ans << " \n"[i == n-1];
    }
  }
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



