#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int a,b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    long long ans = 2 * min(a,b);
    if (a < b) swap(a,b);
    a -= b;
    if (a > 0) {
        ans += 2 * a - 1;
    }
    cout << ans << '\n';
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





