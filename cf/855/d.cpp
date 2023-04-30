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
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    int now = i;
    char f = s[i];
    char w = s[i+1];
    while (now < n-1 && s[now] == f && s[now + 1] == w) {
      now += 1;
      swap(f,w);
    }
    ans += 1;
    i = now-1;
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





