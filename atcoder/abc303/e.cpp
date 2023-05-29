#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<set<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    adj[v].emplace(u);
    adj[u].emplace(v);
  }
  set<ii> pq;
  for (int v = 0; v < n; v++) {
    if (!adj[v].empty()) {
      pq.emplace(adj[v].size(), v);
    }
  }
  vector<int> ans;
  while (!pq.empty()) {
    int v = pq.begin()->second;
    pq.erase(pq.begin());
    if (adj[v].empty()) {
      continue;
    }
    int now = 0;
    assert((int)adj[v].size() == 1);
    int x = *adj[v].begin();
    pq.erase(ii(adj[x].size(), x));
    vector<int> que;
    vector<ii> remove;
    for (auto u : adj[x]) {
      now++;
      pq.erase(ii(adj[u].size(), u));
      for (auto y : adj[u]) {
        if (u != x) {
          remove.emplace_back(y, u);
        }
      }
      que.emplace_back(u);
    }
    for (auto [y, me] : remove) {
      pq.erase(ii(adj[y].size(), y));
      adj[y].erase(me);
      pq.emplace(adj[y].size(), y);
    }
    for (auto u : que) {
      adj[u].clear();
    }
    adj[x].clear();
    ans.emplace_back(now);
  }
  sort(ans.begin(), ans.end());
  for (auto u : ans) {
    cout << u << ' ';
  }
  cout << '\n';
}





