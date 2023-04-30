#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

bool check(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

void solve() {
  int n,k;
  cin >> n >> k;
  string s,t;
  cin >> s >> t;
  if (!check(s,t)) {
    return (void)(cout << "no\n");
  }
  if (s == t) {
    cout << "yes\n";
    return;
  }
  if (k >= n) {
    cout << "no\n";
    return;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (i + k >= n && i - k < 0) {
      ok &= s[i] == t[i];
    }
  }
  cout << (ok ? "yes\n" : "no\n");
  /* //0   12 */
  /* //1   02 */
  /* //2   01 */
  /* //0   21 */

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





