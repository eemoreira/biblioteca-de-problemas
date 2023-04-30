#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int MAX = 2e5+5;
bool isp[MAX];
namespace sieve {
  int lp[MAX+1], factor[MAX+1];
  vector <int> pr;
  void build() {
    for (int i = 2; i <= MAX; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= MAX; ++j) {
        lp[i * pr[j]] = pr[j];
        factor[i * pr[j]] = i;
        if (pr[j] == lp[i]) break;
      }
    }
    for (auto u : pr) {
      isp[u] = true;
    }
  }
  vector<int> factorize(int x) {
    if (x < 2) return {};
    vector <int> v;
    for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
    return v;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int t = i+2;
    int num = a[i];
    bool now = false;
    long long p = 1;
    for (int j = 2; j <= i+2 && p <= 1e9; j++) {
      if (isp[j]) p *= 1LL * j;
      if (a[i]%j) {
        now = true;
        break;
      }
    }
    ok &= now;
  }
  cout << (ok ? "yes\n" : "no\n");
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int t = tt;
  sieve::build();
  while (tt--) {
    int test = t - tt;
    dbg(test);
    solve();
  }
}





