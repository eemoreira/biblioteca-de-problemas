#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  vector<int> f(26);
  iota(f.begin(), f.end(), 0);
  for (int i = 0; i < n && k; i++) {
    int now = s[i] - 'a';
    while (now && f[now] && k) {
      for (int j = now; j >= max(0,now - k); j--) {
        f[now] = min(f[now],f[j]);
      }
      k--;
      now--;
    }
  }
  dbg(f);
  for (auto u : s) {
    cout << char(f[u-'a'] + 'a');
  }
  cout << '\n';
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





