#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int x;
  cin >> x;
  if (x & 1) {
    cout << "Bob\n";
    return;
  }
  if ((x & -x) != x) {
    cout << "Alice\n";
    return;
  }
  cout << (__lg(x) & 1 ? "Bob\n" : "Alice\n");
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





