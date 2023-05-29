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

bool simulate(multiset<int> a, int x) {
  vector<ii> ans;
  int xans = x;
  while (!a.empty()) {
    int now = *a.rbegin();
    auto it = a.end();
    --it;
    a.erase(it);
    it = a.find(x - now);
    if (it == a.end()) {
      return false;
    }
    ans.emplace_back(now, *it);
    a.erase(it);
    x = now;
  }
  cout << "YES\n";
  cout << xans << '\n';
  for (auto [u, v] : ans) {
    cout << u << ' ' << v << '\n';
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  multiset<int> a;
  for (int i = 0; i < n << 1; i++) {
    int x;
    cin >> x;
    a.emplace(x);
  }
  auto it = a.rbegin();
  it++;
  while (it != a.rend()) {
    if (simulate(a, *a.rbegin() + *it)) {
      return;
    }
    it++;
  }
  cout << "NO\n";
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





