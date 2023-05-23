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

const int maxn = 5005;
int dp[maxn][maxn];
ll p[maxn], invp[maxn];
const ll P = 41;
const int mod = 1e9 + 7;
int n;

vector<int> calc(string& s) {
  vector<int> hashs(n);
  for (int i = 0; i < n; i++) {
    hashs[i] = 1ll * (s[i] - 'a' + 1) * p[i] % mod;
    if (i > 0) {
      hashs[i] = (0ll + hashs[i] + hashs[i - 1]) % mod;
    }
  }
  return hashs;
}

vector<int> pre_hash, suf_hash;
int ans[maxn];

int get_pre_hash(int i, int j) {
  if (i == 0) {
    return pre_hash[j];
  }
  return (0ll + pre_hash[j] - pre_hash[i - 1] + mod) % mod * 1ll * invp[i] % mod;
}

int get_suf_hash(int i, int j) {
  if (i == 0) {
    return suf_hash[j];
  }
  return (0ll + suf_hash[j] - suf_hash[i - 1] + mod) % mod * 1ll * invp[i] % mod;
}

bool is(int l, int r) {
  return get_pre_hash(l, r) == get_suf_hash(n - r - 1, n - l - 1);
}

inline int go(int l, int r) {
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  dp[l][r] = 0;
  if (is(l, r)) {
    ans[1]++;
    dp[l][r] = 1;
  }
  int sz = r - l + 1;
  if (sz > 1) {
    int midpre = l + sz / 2 - 1;
    int midsuf = l + sz / 2 + (sz & 1);
    if (get_pre_hash(l, midpre) == get_pre_hash(midsuf, r) && go(l, midpre) == go(midsuf, r) && go(l, midpre) > 0) {
      dp[l][r] = dp[l][midpre] + 1;
      ans[dp[l][r]]++;
      int cnt = 2;
      while (sz > 1 && go(l, midpre) > 1 && is(l, midpre)) {
        ans[cnt++]++;
        sz = midpre - l + 1;
        midpre = l + sz / 2 - 1;
      }
    }
  }
  return dp[l][r];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  string s;
  cin >> s;
  n = s.size();
  p[0] = invp[0] = 1;
  for (int i = 1; i < n; i++) {
    p[i] = 1ll * p[i - 1] * P % mod;
    invp[i] = 1;
    int e = mod - 2;
    ll b = p[i];
    while (e) {
      if (e & 1) {
        invp[i] = 1ll * invp[i] * b % mod;
      }
      b = b * b % mod;
      e >>= 1;
    }
  }

  pre_hash = calc(s);
  reverse(s.begin(), s.end());
  suf_hash = calc(s);
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
    ans[1]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      go(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}





