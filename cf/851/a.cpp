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
  vector<long long> a(n);
  int all = 0;
  for (auto &u : a) {
    cin >> u;
    if (u == 2) all++;
  }
  int c = 0;
  for (int i = 0; i < n-1; i++) {
    if (a[i] == 2) {
      c++;
      all--;
    }
    if (all == c) {
      cout << i+1 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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





