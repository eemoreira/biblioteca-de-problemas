#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if (n > 3 && n%3 == 1) {
    n = (n + 2)/3;
    cout << 4LL * n << '\n';
  }
  else {
    cout << 1 + 2LL*n - (2*((n-2)/3)) << '\n';
  }
}





