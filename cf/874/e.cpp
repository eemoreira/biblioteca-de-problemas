#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
bool vis[maxn];
int tripa = 0;
bool y = false;

void dfs(int v, int origin, int size) {
  vis[v] = true;
  int cnt = 0;
  for (auto u : adj[v]) {
    if (!vis[u]) {
      dfs(u, origin, size + 1);
      cnt++;
    }
  }
  if (cnt == 0) {
    dbg(size, v, origin);
    bool ok = true;
    for (auto u : adj[v]) {
      ok &= u != origin;
    }
    y |= size <= 2 || ok;
  }
}

void solve() {
  int n;
  cin >> n;
  tripa = 0;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    vis[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --x;
    adj[x].emplace_back(i);
    adj[i].emplace_back(x);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      y = false;
      dfs(i, i, 1);
      mx++;
      tripa += y;
    }
  }
  cout << (tripa == 0 ? mx : mx - tripa + 1) << ' ' << mx << '\n';
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





