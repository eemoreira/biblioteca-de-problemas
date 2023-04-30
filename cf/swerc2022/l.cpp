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
  string s;
  cin >> n >> s >> q;
  int pos = 0, neg = 0;
  for (auto u : s) {
    pos += u == '+';
    neg += u == '-';
  }
  dbg(pos,neg);
  while (q--) {
    long long a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a,b);
    }
    long long all = a * pos - b * neg;
    if (all == 0) {
      cout << "YES\n";
    }
    else if (all < 0) {
      cout << "NO\n";
    }
    else {
      long long h = a - b;
      if (h && all % h == 0 && all <= h * n) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}





