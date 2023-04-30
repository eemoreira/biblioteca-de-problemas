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
  vector<string> a(2 * n - 2);
  for (auto &u : a) {
    cin >> u;
  }
  sort(a.begin(), a.end(), [&](string l, string r) { return l.size() < r.size();});
  bool ok = true;
  for (int i = 0; i < 2 * n - 2; i += 2) {
    string l = a[i];
    string r = a[i + 1];
    reverse(r.begin(), r.end());
    ok &= l == r;
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





