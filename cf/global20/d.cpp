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
  vector<int> a(n), b(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  int ptr = n-1;
  vector<int> f(n+1);
  bool ok = true;
  for (int i = n-1; i >= 0; i--) {
    while (ptr > 0 && b[ptr] == b[ptr-1]) {
      ptr--;
      f[b[ptr]]++;
    }
    dbg(i,ptr);
    if (ptr < 0 || a[i] != b[ptr]) {
      if (!f[a[i]]) {
        ok = false;
        break;
      }
      f[a[i]]--;
    }
    else {
      ptr--;
    }
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





