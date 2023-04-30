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
  vector<int> num;
  long long t = n;
  while (t) {
    num.emplace_back(t%10);
    t /= 10;
  }
  vector<int> a((int)num.size());
  int x = 0;
  for (int i = 0; i < (int)num.size(); i++) {
    if (num[i]&1) {
      a[i] = (num[i]+x)/2;
      num[i] = (num[i] + !x)/2;
      x ^= 1;
    }
    else {
      a[i] = num[i] = num[i]/2;
    }
  }
  dbg(a,num);
  int ans = 0;
  t = 1;
  for (auto u : a) {
    ans += t * u;
    t *= 10;
  }
  cout << ans << ' ';
  ans = 0;
  t = 1;
  for (auto u : num) {
    ans += t * u;
    t *= 10;
  }
  cout << ans << '\n';
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





