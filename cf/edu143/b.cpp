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
  cin >> n >> k;
  vector<int> f(55), t(55);
  for (int i = 0; i < n; i++) {
    int l,r;
    cin >> l >> r;
    f[l]++;
    t[r]++;
  }
  cout << (f[k] && t[k] ? "yes\n" : "no\n");
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





