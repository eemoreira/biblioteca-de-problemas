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

void solve(){
  int n,k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  vector<int> a(n);
  for(auto &u : a){
    cin >> u;
  }
  for(int i = 1; i < n; i++){
    int u,v;
    cin >> u >> v;
    --u;--v;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  int end = 0;
  for(auto u : a) end ^= u;
  vector<bool> vis(n,false);
  function<pair<int,int>(int)> Dfs = [&](int v) {
    int subs = 0;
    if(k > 2){
      vis[v] = true;
      int xo = a[v];
      for(auto u : adj[v]){
        if(!vis[u]){
          auto t = Dfs(u);
          xo ^= t.first;
          if(t.second == 1){
            subs = min(2, subs+1);
          }
          if(t.second == 2){
            subs = 2;
          }
        }
      }
      if(subs == 1 && !xo) subs = 2;
      if(!subs && xo == end) subs = 1;
      return make_pair(xo,subs);
    }
    return make_pair(-1,0);
  };
  cout << (!end || Dfs(0).second == 2 ? "yes\n" : "no\n");
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



