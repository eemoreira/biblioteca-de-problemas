#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int p = 41;
const int MX = 2e5 + 5;
pair<long long, long long> dp[MX], dp2[MX];
long long pw1[MX], pw2[MX];
vector<int> adj[MX];

void dfs(int x, int v) {
  dp[v] = {1, 1};
  for (auto u : adj[v]) {
    if (u != x) {
      dfs(v,u);
      dp[v].first += p * dp[u].first % mod1;
      dp[v].first %= mod1;
      dp[v].second += p * dp[u].second % mod2;
      dp[v].second %= mod2;
    }
  }
}

void dfs2(int x, int v) {
  dp2[v].first = (dp[x].first - p * dp[v].first % mod1 + p * dp2[x].first % mod1) % mod1;
  dp2[v].second = (dp[x].second - p * dp[v].second % mod2 + p * dp2[x].second % mod2) % mod2;
  if (dp2[v].first < 0) dp2[v].first += mod1;
  if (dp2[v].second < 0) dp2[v].second += mod2;
  if (v == 0) {
    dp2[v] = {0,0};
  }
  for (auto u : adj[v]) {
    if (u != x) {
      dfs2(v,u);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < n; i++) {
    pw1[i] = pw1[i-1] * p % mod1;
    pw2[i] = pw2[i-1] * p % mod2;
  }
  long long e1,e2;
  e1 = e2 = 0;
  vector<int> f(n+1);
  for (int i = 0; i < n-1; i++) {
    int x;
    cin >> x;
    f[x] += 1;
  }
  for (int i = 0; i < n; i++) {
    e1 = (e1 + f[i] * pw1[i] % mod1) % mod1;
    e2 = (e2 + f[i] * pw2[i] % mod2) % mod2;
  }
  map<long long, int> have1, have2;
  for (int i = 0; i < n; i++) {
    have1[(e1 + pw1[i]) % mod1] = 1;
    have2[(e2 + pw2[i]) % mod2] = 1;
  }
  for (int i = 1; i < n; i++) {
    int v,u;
    cin >> v >> u;
    --v; --u;
    adj[v].emplace_back(u);
    adj[u].emplace_back(v);
  }
  dfs(0,0);
  dfs2(0,0);
  int k = 0;
  vector<int> ans;
  dbg(have1);
  dbg(have2);
  for (int i = 0; i < n; i++) {
    long long x = (dp[i].first + p * dp2[i].first % mod1) % mod1;
    long long y = (dp[i].second + p * dp2[i].second % mod2) % mod2;
    dbg(x,y);
    if (have1[x] && have2[y]) {
      ans.emplace_back(i+1);
      k++;
    }
  }
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " \n"[i+1 == k];
  }
}





