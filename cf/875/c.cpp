#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<i64,i64>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
vector<ii> adj[maxn];
int ans = 1;

void dfs(int v, int came = -1, int p = -1, int now = 1) {
  ans = max(ans, now);
  for (auto [u, i] : adj[v]) {
    if (u != p) {
      if (i < came) {
        dfs(u, i, v, now + 1);
      }
      else {
        dfs(u, i, v, now);
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  vector<int> pos(n, 1e9);
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    adj[v].emplace_back(u, i);
    adj[u].emplace_back(v, i);
  }
  ans = 1;
  dfs(0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





