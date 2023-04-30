#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

vector<long long> go(bool r, vector<long long> a) {
  int n = a.size();
  vector<long long> p(n+1), b(n);
  if (!r) {
    reverse(a.begin(), a.end());
  }
  for (int i = 0; i < n; i++) {
    b[i] = a[i] + i;
  }
  for (int i = 1; i <= n; i++) {
    p[i] = p[i-1] + a[i-1];
  }
  auto nxt = [&]() {
    vector<int> ans(n,n);
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && b[stk.back()] >= b[i]) {
        ans[stk.back()] = i;
        stk.pop_back();
      }
      stk.emplace_back(i);
    }
    return ans;
  };
  vector<int> nmi = nxt();
  dbg(p,b,nmi);
  vector<long long> dp(n);
  for (int i = n-1; i >= 0; i--) {
    if (nmi[i] > i+1) {
      dp[i] = p[nmi[i]] - p[i+1];
      if (a[i] > 0) {
        long long v = nmi[i] - i - 1;
        dbg(i,v,a[i],dp[i]);
        if (a[i] - 1 <= v) {
          dbg(a[i] * (a[i] - 1) / 2);
          dp[i] -= (a[i] * (a[i] - 1))/2;
        }
        else {
          dbg((a[i] - 1 + a[i] - v) * v / 2);
          dp[i] -= ((a[i] - 1 + a[i] - v) * v)/2;
        }
      }
    }
    if (nmi[i] < n) {
      dp[i] += dp[nmi[i]];
    }
  }
  return dp;
}

void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> dp1 = go(true,a);
  vector<long long> dp2 = go(false,a);
  long long ans = 1e18;
  dbg(dp1,dp2);
  for (int i = 0; i < n; i++) {
    dbg(a[i],dp1[i],dp2[n-i-1]);
    ans = min(ans, a[i] + dp1[i] + dp2[n-i-1]);
  }
  cout << ans << '\n';
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





