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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  sort(a.begin(), a.end());
  vector<int> stk;
  vector<i64> dp(n + 1, -1);
  dp[0] = 0;
  vector<int> f(n + 1);
  for (int i = 0; i < n; i++) {
    f[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (i > 0) {
      for (int j = 0; j < f[i - 1] - 1; j++) {
        stk.emplace_back(i - 1);
      }
      if (f[i - 1]) {
        dp[i] = dp[i - 1];
      }
      else if (stk.empty()) {
        break;
      }
      else {
        dp[i] = dp[i - 1] + i - 1 - stk.back();
        stk.pop_back();
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i] != -1) {
      dp[i] += f[i];
    }
    cout << dp[i] << " \n"[i == n];
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





