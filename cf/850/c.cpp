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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long ans = 0;
  sort(a.begin(), a.end());
  int last = 1;
  for (int i = 0; i < n;) {
    ans += a[i] - last;
    if (a[i] == last) {
      while (i < n && a[i] == last) {
        i++;
      }
    }
    else {
      i++;
    }
    last++;
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





