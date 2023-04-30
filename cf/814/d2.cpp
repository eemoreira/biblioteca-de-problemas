#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
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
  vector<int> p(n+1);
  for (int i = 1; i <= n; i++) {
    p[i] = a[i-1] ^ p[i-1];
  }
  set<int> s;
  int ans = n;
  s.emplace(0);
  for (int i = 1; i <= n; i++) {
    if (s.find(p[i]) != s.end()) {
      ans--;
      s.clear();
    }
    s.emplace(p[i]);
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





