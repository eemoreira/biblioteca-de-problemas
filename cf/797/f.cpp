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
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> vis(n);
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    int t = i;
    string wtf = "";
    while (!vis[t]) {
      wtf += s[t];
      vis[t] = 1;
      t = a[t];
    }
    int k = wtf.size();
    int y = k;
    auto check = [&](int j) {
      bool ok = true;
      string nice = wtf.substr(0,j);
      for (int e = 0; e < k; e += j) {
        ok &= nice == wtf.substr(e,j);
      }
      return ok;
    };
    for (int j = 1; j*j <= k; j++) {
      if (k % j == 0) {
        if (check(j)) {
          y = min(y,j);
        }
        if (check(k / j)) {
          y = min(y,k / j);
        }
      }
    }
    dbg(wtf, y);
    ans = lcm(ans, y);
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





