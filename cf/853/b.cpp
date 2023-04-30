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
  int l = 0, r = n-1;
  vector<int> id;
  while (l < r) {
    bool cp = s[l] == s[r];
    if (s[l] != s[r]) {
      id.emplace_back(l);
    }
    l++;
    r--;
  }
  bool ok = true;
  for (int i = 1; i < (int)id.size(); i++) {
    ok &= id[i] == id[i-1] + 1;
  }
  cout << (ok ? "yes\n" : "no\n");
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





