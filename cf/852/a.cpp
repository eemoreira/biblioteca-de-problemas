#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  long long a,b,n,m;
  cin >> a >> b >> n >> m;
  dbg(b * (m+1), a * m);
  if (n < m) {
    cout << min(a,b) * n << '\n';
  }
  else if (a <= b) {
    long long f = m++;
    long long nx = n/m;
    dbg(nx);
    cout << a * (f * nx) + a * (n - m * nx) << '\n';
  }
  else if (b * (m+1) <= a * m) {
    cout << b * n << '\n';
  }
  else {
    long long f = m++;
    long long nx = n/m;
    dbg(nx);
    cout << a * (f * nx) + b * (n - m * nx) << '\n';
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





