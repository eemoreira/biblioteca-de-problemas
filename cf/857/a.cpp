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
  int pos = 0;
  int neg = 0;
  for (auto &u : a) {
    cin >> u;
    pos += u > 0;
    neg += u < 0;
  }
  for (int i = 0; i < pos; i++) cout << i+1 << ' ';
  for (int i = 0; i < neg; i++) cout << pos - i - 1 << ' ';
  cout << '\n';
  int x = 1;
  while (pos && neg) {
    cout << x << ' ';
    if (x) pos--;
    else neg--;
    x ^= 1;
  }
  x ^= 1;
  for (int i = 0; i < pos; i++) cout << x + i + 1 << ' ';
  for (int i = 0; i < neg; i++) cout << x - i - 1 << ' ';
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





