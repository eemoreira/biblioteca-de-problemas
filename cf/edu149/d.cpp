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

bool check(string s) {
  vector<int> stk;
  int n = s.size();
  bool ok = false;
  for (int t = 0; t < 2; t++) {
    dbg(s);
    bool d = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.emplace_back(i);
      }
      else {
        if (stk.empty()) {
          d = false;
          break;
        }
        stk.pop_back();
      }
    }
    ok |= d && stk.empty();
    reverse(s.begin(), s.end());
  }
  return ok;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char,int> f;
  for (auto u : s) {
    f[u]++;
  }
  if (f['('] != f[')']) {
    cout << -1 << '\n';
    return;
  }
  if (check(s)) {
    cout << 1 << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }
  vector<int> stk, ans(n, 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.emplace_back(i);
    }
    else {
      if (stk.empty()) {
        ans[i] = 2;
      }
      else {
        stk.pop_back();
      }
    }
  }
  for (auto u : stk) {
    ans[u] = 2;
  }
  cout << 2 << '\n';
  for (int i = 0; i < n ; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
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





