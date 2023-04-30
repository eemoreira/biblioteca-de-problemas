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
  int sum = 0;
  for (auto &u : a) {
    cin >> u;
    sum += u;
  }
  bool ok = false;
  if (a == vector<int>(n, a[0])) {
    ok = true;
  }
  for (int i = 0; i < n; i++) {
    if ((sum-a[i])%(n-1)) continue;
    if ((sum-a[i])/(n-1) == a[i]) {
      ok = true;
    }
  }
  cout << (ok ? "yes\n" : "no\n");
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





