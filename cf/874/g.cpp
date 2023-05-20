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
int sz[maxn];
int keep[maxn];
vector<int> ans;

bool ok = true;
map<int, map<int,int>> ed;

void dfs(int v, int p) {
  sz[v] = 1;
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
  }
  if (sz[v] == 3) {
    if (v != p) {
      ans.emplace_back(ed[p][v]);
    }
    sz[v] = 0;
  }
  else if (sz[v] > 3) {
    ok = false;
  }
}

void solve() {
  int n;
  cin >> n;
  ans.clear();
  ed.clear();
  ok = true;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    sz[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    ed[v][u] = i;
    ed[u][v] = i;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  if (n % 3) {
    cout << -1 << '\n';
  }
  else {
    dfs(0, 0);
    if (!ok) {
      cout << -1 << '\n';
    }
    else {
      assert((int)ans.size() == n / 3 - 1);
      cout << n / 3 - 1 << '\n';
      for (auto u : ans) {
        cout << u << ' ';
      }
      cout << '\n';
    }
  }
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





