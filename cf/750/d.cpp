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
  int mn = 1e9;
  for (auto &u : a) {
    cin >> u;
  }
  int check = 0;
  if (n%2==0) {
    for (int i = 0; i < n-1; i+=2) {
      cout << a[i+1] << ' ' << -a[i] << ' ';
    }
  }
  else {
    cout << abs(a[2]) * (a[0] < 0 ? -1 : 1)  << ' ' << abs(a[2]) * (a[1] < 0 ? -1 : 1)  << ' ' << (abs(a[0]) + abs(a[1])) * (a[2] < 0 ? 1 : -1) << ' ';
    for (int i = 3; i < n-1; i+=2) {
      cout << a[i+1] << ' ' << -a[i] << ' ';
    }
  }
  cout << '\n';
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






