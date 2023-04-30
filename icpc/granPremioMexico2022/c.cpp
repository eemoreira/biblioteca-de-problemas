#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<long long> a(n);
  long long ans = 0;
  for (auto &u : a) {
      cin >> u;
      ans += u;
  }
  sort(a.begin(), a.end());
  int ptr = n-1;
  int y = 0;
  dbg(ans);
  while (q--) {
      int v;
      cin >> v;
      while (ptr >= 0 && a[ptr] > v) {
          ans -= a[ptr];
          ptr--;
          y++;
      }
      dbg(y);
      cout << ans + 1LL * y * v << '\n';
  }
}





