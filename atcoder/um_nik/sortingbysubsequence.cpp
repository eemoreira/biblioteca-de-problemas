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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<vector<int>> ans;
  vector<ii> s;
  for (int i = 0; i < n; i++) {
    s.emplace_back(a[i], i);
  }
  sort(s.begin(), s.end());
  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    int t = i;
    vector<int> now;
    while (s[t].first != a[t]) {
      vis[t] = 1;
      now.emplace_back(t);
      swap(a[t], a[s[t].second]);
      t = s[t].second;
    }
    now.emplace_back(t);
    vis[t] = 1;
    ans.emplace_back(now);
  }
  cout << ans.size() << '\n';
  for (auto u : ans) {
    cout << u.size() << ' ';
    for (auto x : u) {
      cout << x+1 << ' ';
    }
    cout << '\n';
  }
}





