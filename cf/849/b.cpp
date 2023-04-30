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
  int x = 0;
  int y = 0;
  for (auto u : s) {
    if (u == 'L') {
      x--;
    }
    if (u == 'R') {
      x++;
    }
    if (u == 'U') {
      y++;
    }
    if (u == 'D') {
      y--;
    }
    if (x == 1 && y == 1) {
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
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





