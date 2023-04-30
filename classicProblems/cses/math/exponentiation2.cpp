#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  const int mod = 1e9 + 7;
  long long a,b,c;
  cin >> a >> b >> c;
  if (b == 0 && c == 0) {
    cout << a << '\n';
    return; 
  }
  if (a == 0) {
    cout << (b == 0 && c != 0 ? 1 : 0) << '\n';
    return;
  }
  auto bpw = [&](long long x, int m, int e) {
    long long ans = 1;
    while (e) {
      if (e & 1) {
        ans = x * ans % m;
      }
      x = x * x % m;
      e >>= 1;
    }
    return ans;
  };
  cout << bpw(a, mod, bpw(b, mod-1, c)) << '\n';
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





