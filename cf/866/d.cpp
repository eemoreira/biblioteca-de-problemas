#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
#define int long long
void solve() {
  int n;
  cin >> n;
  vector<ii> a(n);
  ll area = 0;
  ll L = 0, R = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    area += a[i].first * a[i].second;
    L = max(L, a[i].first);
    R = max(R, a[i].second);
  }
  if (n == 1) {
    cout << 1 << '\n';
    cout << L << ' ' << R << '\n';
    return;
  }
  vector<ii> ans;
  auto check = [&](ll l, ll w) {
    map<ll, set<int>> len, width;
    ans.emplace_back(l, w);
    for (int i = 0; i < n; i++) {
      len[a[i].first].emplace(i);
      width[a[i].second].emplace(i);
    }
    for (int i = 0; i < n; i++) {
      if (!len[l].empty()) {
        int j = *len[l].begin();
        len[l].erase(j);
        width[a[j].second].erase(j);
        w -= a[j].second;
      }
      else if (!width[w].empty()) {
        int j = *width[w].begin();
        len[a[j].first].erase(j);
        width[w].erase(j);
        l -= a[j].first;
      }
      else {
        ans.pop_back();
        break;
      }
    }
  };
  if (area % R == 0) {
    dbg(area / R, R);
    check(area / R, R);
  }
  if (area % L == 0) {
    check(L, area / L);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << '\n';
  for (auto u : ans) {
    cout << u.first << ' ' << u.second << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





