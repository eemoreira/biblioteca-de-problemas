#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  long long n,x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += abs(a[i] - a[i+1]);
  }
  long long m = 1e18;
  for (int j = 0; j < 2; j++) {
    m = min(m, x - 1 + min(abs(a[0] - 1), abs(a[0] - x)));
    long long last = abs(a[0] - 1);
    for (int i = 0; i < n-1; i++) {
      m = min(m, -abs(a[i] - a[i+1]) + last + abs(a[i] - x) + abs(a[i+1] - x));
      m = min(m, -abs(a[i] - a[i+1]) + x-1 + abs(a[i+1]-x) + abs(a[i]-1));
      last = min(last, -abs(a[i] - a[i+1]) + abs(a[i] - 1) + abs(a[i+1] - 1));
    }
    m = min(m, x - 1 + min(abs(a.back() - 1), abs(a.back() - x)));
    m = min(m, last + abs(a.back() - x));
    reverse(a.begin(), a.end());
  }
  dbg(ans,m);
  cout << ans + m << '\n';
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





