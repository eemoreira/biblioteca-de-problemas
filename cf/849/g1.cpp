#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n,c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] += i+1;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int ptr = 0;
  while (ptr < n && c >= a[ptr]) {
    c -= a[ptr];
    ptr++;
    ans++;
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






