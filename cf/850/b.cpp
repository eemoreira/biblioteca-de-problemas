#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  long long n,w,h;
  cin >> n >> w >> h;
  vector<long long> a(n), b(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  long long mx = -1e18;
  long long mn = 1e18;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i] - w - (b[i] - h));
    mn = min(mn, a[i] + w - (b[i] + h));
  }
  cout << (mn >= mx ? "yes\n" : "no\n");
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





