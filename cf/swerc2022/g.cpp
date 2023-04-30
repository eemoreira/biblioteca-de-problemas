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
  int n;
  cin >> n;
  int k = (n + 1) >> 1;
  int ans = -1;
  string s;
  cin >> s;
  vector<int> p(2*n);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i-1] + (s[i-1] == 'W');
  }

}





