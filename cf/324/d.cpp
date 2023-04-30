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
  auto isp = [&](int num) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i*i <= num; i++) {
      if (num%i==0) {
        return false;
      }
    }
    return true;
  };
  if (isp(n)) {
    cout << 1 << '\n';
    cout << n << '\n';
    return 0;
  }
  if (isp(n-2)) {
    cout << 2 << '\n';
    cout << 2 << ' ' << n-2 << '\n';
    return 0;
  }
  cout << 3 << '\n';
  int t = n-3;
  while (true) {
    if (isp(t)) {
      cout << t << ' ';
      n -= t;
      break;
    }
    t--;
  }
  for (int i = 2; i <= n; i++) {
    if (isp(i) && isp(n-i)) {
      cout << i << ' ' << n-i << '\n';
      return 0;
    }
  }
  assert(false);
}





