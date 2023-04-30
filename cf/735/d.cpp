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
  int k = n / 2;
  string ans = "";
  for (int i = 0; i < k; i++) {
    cout << 'a';
  }
  cout << 'b';
  if ((n & 1) && n > 1) {
    cout << 'c';
  }
  for (int i = 0; i < k - 1; i++) {
    cout << 'a';
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





