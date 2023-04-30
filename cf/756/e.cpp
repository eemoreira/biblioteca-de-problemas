#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
/* stop freaking out pls */
const int N = 2e5 + 5;
vector<int> adj[N];

namespace st {
  int n, me;
  vector<vector<int>> up;
  vector<int> d;
  void bl_dfs(int v, int p) {
    up[v][0] = p;
    for(int i = 1; i <= me; i++){
      up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u : adj[v]){
      if(u != p){
        d[u] = d[v] + 1;
        bl_dfs(u, v);
      }
    }
  }
  void build(int _n, int root){
    n = _n;
    me = __lg(n) + 1;
    up.assign(n, vector<int>(me+1, 0));
    d.assign(n, 0);
    bl_dfs(root, root);
  }
  int ancestor(int v, int k){ // k-th ancestor of u 
    for(int i = me; i >= 0; i--){
      if((1 << i) & k){
        v = up[v][i];
      }
    }
    return v;
  }
  int depth(int v) {
    return d[v];
  }
}
void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> mark(n);
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    --v;
    mark[v]++;
  }
  for (int i = 1; i < n; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  st::build(n,0);
  vector<int> best(n);
  function<pair<int,int>(int,int)> findbest = [&](int v, int p) {
    best[v] = mark[v] ? st::depth(v) : 1e9;
    pair<int,int> big = {best[v],v};
    for (auto u : adj[v]) {
      if (u != p) {
        big = min(findbest(u,v), big);
      }
    }
    best[v] = big.first == 1e9 ? -1 : big.second;
    return big;
  };
  findbest(0,0);
  dbg(best);
  function<bool(int, int, int)> Dfs = [&](int v, int p, int cnt) {
    if (best[v] == -1) {
      return true;
    }
    int gt = st::ancestor(best[v],cnt);
    if (st::depth(gt) <= st::depth(v)) {
      return false;
    }
    mark[gt] = 1;
    bool ok = false;
    for (auto u : adj[v]) {
      if (u != p && !mark[u]) {
        ok |= Dfs(u,v,cnt+1);
      }
    }
    return ok;
  };
  cout << (Dfs(0,0,0) ? "yes\n" : "no\n");
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




