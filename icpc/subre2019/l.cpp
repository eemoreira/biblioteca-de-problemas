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
  long long n;
  cin >> n;
  int ans = 0;
  while (n) {
    ans += n & 1;
    n >>= 1;
  }
  cout << (1LL << ans) << '\n';
}






