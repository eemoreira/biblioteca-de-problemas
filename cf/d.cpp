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
int a[N];
int n,m,k;

void bfs(int root, vector<int>& d) {
  queue<int> q;
  d[root] = 0;
  q.emplace(root);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : adj[v]) {
      if (d[u] > d[v] + 1) {
        d[u] = d[v] + 1;
        q.emplace(u);
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    a[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    --v;
    a[v]++;
  }
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector<int> dS(n,1e9), dF(n,1e9);
  bfs(0,dS);
  bfs(n-1,dF);
  vector<int> w;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      w.emplace_back(i);
    }
  }
  sort(w.begin(), w.end(), [&](int v, int u){ return dS[v] < dS[u];});
  int ans = 0;
  vector<int> mx(k+1, -1e9);
  for (int i = k-1; ~i; i--) {
    mx[i] = max(mx[i+1], dF[w[i]]);
  }
  dbg(w, mx);
  for (int i = 0; i < k; i++) {
    ans = max(ans, 1 + dS[w[i]] + mx[i+1]);
  }
  cout << min(dF[0],ans) << '\n';
}





