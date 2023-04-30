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
  string s;
  cin >> n >> s;
  int l = 0;
  int r = n-1;
  while (l <= r) {
    if (s[l] == s[r]) break;
    l++;
    r--;
  }
  cout << max(r-l+1, 0) << '\n';
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





