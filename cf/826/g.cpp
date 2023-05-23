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

const int maxn = 1e4 + 5;
vector<int> adj[maxn];
int a[maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  int f;
  cin >> f;
  for (int i = 0; i < f; i++) {
    cin >> a[i];
    --a[i];
  }
  int k;
  cin >> k;
  vector<int> notcar(f);
  vector<vector<int>> who(n);
  int y = 0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    --x;
    notcar[x] = 1;
    who[a[x]].emplace_back(y++);
  }
  dbg(k);
  vector<vector<int>> dp(n, vector<int>(1 << k));
  vector<int> dist(n, 1e9);
  queue<i3> q;
  dist[0] = 0;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    auto [v, mask, d] = q.front();
    q.pop();
    if (dist[v] < d) {
      continue;
    }
    dbg(v, mask, d);
    dp[v][mask] = 1;
    dist[v] = d;
    for (auto u : adj[v]) {
      if (d + 1 <= dist[u]) {
        int nowmask = mask;
        dist[u] = d + 1;
        for (auto w : who[u]) {
          nowmask |= 1 << w; 
        }
        for (int i = 0; i < 1 << k; i++) {
          if (dp[v][i] && !dp[u][i]) {
            dp[u][i] = 1;
            q.emplace(u, i, dist[u]);
          }
        }
        if (!dp[u][nowmask]) {
          dp[u][nowmask] = 1;
          q.emplace(u, nowmask, dist[u]);
        }
      }
    }
  }
  vector<vector<int>> ks(f + 1, vector<int>(1 << k));
  dbg(dp);
  ks[0][0] = 1;
  for (int i = 1; i <= f; i++) {
    if (notcar[i - 1]) {
      ks[i] = ks[i - 1];
      continue;
    }
    for (int j = 0; j < 1 << k; j++) {
      ks[i][j] |= ks[i - 1][j];
      if (dp[a[i - 1]][j]) {
        for (int o = 0; o < 1 << k; o++) {
          ks[i][j | o] |= ks[i - 1][j | o] | ks[i - 1][o];
        }
      }
    }
  }
  dbg(ks);
  int ans = 0;
  for (int i = 0; i < 1 << k; i++) {
    if (ks[f][i]) {
      ans = max(ans, __builtin_popcount(i));
    }
  }
  cout << k - ans << '\n';
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
