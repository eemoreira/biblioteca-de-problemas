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
  int ok = 0;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  int l = n;
  int r = 0;
  for (int i = 0; i < n-1; i++) {
    if (a[i] == a[i+1]) {
      ok += 1;
      r = max(r, i);
      l = min(l, i+1);
    }
  }
  dbg(l,r);
  cout << (ok <= 1 ? 0 : r - l + (r == l)) << '\n';
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





