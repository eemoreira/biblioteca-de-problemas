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
    if (u == 1) {
      u = 2;
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] % a[i-1] == 0) {
      a[i] += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i+1 == n];
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





