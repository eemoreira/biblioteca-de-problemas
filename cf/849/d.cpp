#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  map<char,int> w,t;
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    w[s[i]]++;
  }
  int ans = w.size();
  int cntw = w.size();
  int cntt = 0;
  for (int i = 0; i < n; i++) {
    if (!t[s[i]]) {
      cntt++;
    }
    t[s[i]]++;
    w[s[i]]--;
    if (!w[s[i]]) {
      cntw--;
    }
    ans = max(ans, cntt + cntw);
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





