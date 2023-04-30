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
  if (n % 2 == 0) {
    cout << "no\n";
    return;
  }
  bool ok = true;
  vector<pair<int,int>> ans(n);
  int f = 2*n;
  cout << "yes\n";
  dbg(f);
  int g = 1;
  int cnt = 0;
  while (g <= n) {
    ans[cnt++] = {g, f};
    g += 2;
    f--;
  }
  g = 2;
  while (g < n) {
    ans[cnt++] = {g,f};
    f--; 
    g+=2;
  }
  for (auto u : ans) {
    cout << u.first << ' ' << u.second << '\n';
  }
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





