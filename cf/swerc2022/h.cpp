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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    --v;
    a[v] = i;
  }
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    --v;
    b[i] = a[v];
  }
  int ans = 0;
  for (int i = n-2; ~i; i--) {
    if (b[i] > b[i+1]) {
      ans = i+1;
      break;
    }
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





