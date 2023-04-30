#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
long long w[25];
int n,x;

int go(int mask) {
  if (mask == (1 << n) - 1) {
    return 0;
  }
  pair<long long ,int> g = {0,0};
  for (int i = 1; i < 1 << n; i++) {
    if (i & mask) continue;
    long long now = 0;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        now += w[j];
      }
    }
    if (now <= x) {
      g = max(g, make_pair(now,i | mask));
    }
  }
  return go(g.second) + 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << go(0) << '\n';
}





