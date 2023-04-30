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
  vector<int> a(n), f(n+1);
  for (auto &u : a) {
    cin >> u;
    f[u]++;
  }
  vector<long long> ans(n+1);
  for (int i = 0; i <= n; i++) {
    ans[i] = f[i];
  }
  int ptr = 0;
  vector<long long> op(n+1);
  bool dr = false;
  for (int i = 0; i < n; i++) {
    if (f[i] == 0) {
      bool ok = false;
      for (int j = ptr; ~j; j--) {
        if (f[j] > 1) {
          f[j]--;
          ok = true;
          op[i+1] = i-j;
          ptr = j;
          break;
        }
      }
      if (!ok) {
        dr = true;
        ptr = i+1;
        break;
      }
    }
    else {
      ptr = i;
    }
  }
  if (dr) {
    for (int i = ptr; i <= n; i++) {
      ans[i] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    op[i] += op[i-1];
  }
  for (int i = 0; i <= n; i++) {
    if (~ans[i]) {
      ans[i] += op[i];
    }
    cout << ans[i] << " \n"[i == n];
  }
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





