#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &u : a) { 
    cin >> u;
  }
  vector<vector<long long>> mod(3);
  for (int i = 0; i < n; i++) {
    long long w = a[i];
    w *= w;
    mod[w%3].emplace_back(i);
  }
  assert(mod[2].empty());
  dbg(mod);
  string ans = string(n, ' ');
  int z = 0;
  if (mod[0].size() >= mod[1].size()) {
    z = 2;
    for (int i = 0; i < n/2; i++) {
      ans[mod[0][i]] = '1';
    }
    for (int i = n/2; i < (int)mod[0].size(); i++) {
      ans[mod[0][i]] = '0';
    }
    for (auto u : mod[1]) {
      ans[u] = '0';
    }
  }
  else {
    for (int i = 0; i < n/2; i++) {
      ans[mod[1][i]] = '1';
    }
    for (int i = n/2; i < (int)mod[1].size(); i++) {
      ans[mod[1][i]] = '0';
    }
    for (auto u : mod[0]) {
      ans[u] = '0';
    }
  }
  cout << z << '\n' << ans << '\n';
}






