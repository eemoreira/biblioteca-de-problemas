#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int N = 1e6 + 6;
const int mod = 998244353;
vector<int> isp(N, 1);
vector<long long> f(N, 1LL);

void solve() {
  int n;
  cin >> n;
  vector<int> notp;
  vector<int> freq(N);
  set<int> s;
  for (int i = 0; i < n << 1; i++) {
    int x;
    cin >> x;
    if (!isp[x] || s.find(x) != s.end()) {
      freq[x] += 1;
      notp.emplace_back(x);
    }
    else {
      s.emplace(x);
    }
  }
  dbg(s,notp);
  if ((int)s.size() < n) {
    cout << 0 << '\n';
    return;
  }
  auto bpw = [&](long long x, long long e) {
    long long ret = 1;
    while (e) {
      if (e & 1) {
        ret = ret * x % mod;
      }
      x = x * x % mod;
      e >>= 1;
    }
    return ret;
  };
  int t = s.size();
  int w = notp.size();
  set<int> now;
  for (auto u : notp) {
    now.emplace(u);
  }
  long long fat = f[n];
  for (auto u : now) {
    fat = fat * bpw(f[freq[u]], mod - 2) % mod;
  }
  dbg(fat);
  if (t == w) {
    cout << fat % mod << '\n';
    return;
  }
  int r = n - w;
  vector<int> a;
  for (auto u : s) {
    a.emplace_back(u);
  }
  n = a.size();
  vector<vector<long long>> dp(n+1, vector<long long>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0) {
        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * bpw(freq[a[i-1]] + 1, mod -2) % mod) % mod;
      }
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
    }
  }
  dbg(dp);
  cout << fat * dp[n][r] % mod << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  isp[1] = 0;
  f[0] = f[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = f[i-1] * i % mod;
    for (int j = i+i; j < N; j+=i) {
      isp[j] = 0;
    }
  }
  solve();
}





