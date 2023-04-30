#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n,m;
  cin >> n;
  cin >> m;
  string s,t;
  cin >> s >> t;
  auto check = [&](string a, string b) {
    bool ok = true;
    for (int i = 1; i < (int)a.size(); i++) {
      ok &= a[i] != a[i-1];
    }
    for (int i = 1; i < (int)b.size(); i++) {
      ok &= b[i] != b[i-1];
    }
    return ok;
  };
  auto solve = [&](string a, string b) {
    while (!a.empty()) {
      if (check(a,b)) {
        return true;
      }
      b += a.back();
      a.pop_back();
    }
    return false;
  };
  cout << (solve(s,t) || solve(t,s) ? "yes\n" : "no\n");
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





