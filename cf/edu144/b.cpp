#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  if (s[0] == t[0]) {
    cout << "yes\n";
    cout << s[0] << "*\n";
    return;
  }
  if (s.back() == t.back()) {
    cout << "yes\n";
    cout << '*' << s.back() << '\n';
    return;
  }
  for (int i = 0; i < n-1; i++) {
    string now = s.substr(i,2);
    for (int j = 0; j < m-1; j++) {
      string q = t.substr(j,2);
      if (now == q) {
        cout << "yes\n";
        cout << '*' << now << '*' << '\n';
        return;
      }
    }
  }
  cout << "no\n";
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





