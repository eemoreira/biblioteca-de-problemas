#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
 
/* stop freaking out pls */
 
const int MAX = 1e6 + 1;
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
  vector<int> w;
  int num = 0;
  vector<pair<int,int>> p;
  function<void(int,long long)> go = [&](int ptr, long long x) {
    if (ptr == num) {
      w.emplace_back(x);
      return;
    }
    for (int i = 0; i <= p[ptr].second; i++) {
      go(ptr+1,x);
      x *= p[ptr].first;
    }
  };
  vector<int> have(MAX);
  for (int i = 0; i < n; i++) {
    vector<int> t = sieve::factorize(a[i]);
    map<int,int> f;
    for (auto u : t) {
      f[u]++;
    }
    p.clear();
    for (auto u : f) {
      p.emplace_back(u.first, u.second);
    }
    w.clear();
    num = f.size();
    go(0,1);
    for (auto u : w) {
      have[u]++;
    }
  }
  int ans = 1;
  for (int i = 1; i < MAX; i++) {
    if (have[i] > 1) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve::build();
  solve();
}
 
