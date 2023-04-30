#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  int n,k;
  long long x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long> g;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '*') {
      long long w = 1;
      while (i >= 0 && s[i] == '*') {
        w += k;
        i--;
      }
      g.emplace_back(w);
    }
  }
  int t = g.size();
  vector<int> am(t);
  x--;
  for (int i = 0; i < t; i++) {
    am[i] = x % g[i];
    x /= g[i];
  }
  dbg(g,am);
  int ptr = 0;
  string ans = "";
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '*' && ptr < t) {
      for (int j = 0; j < am[ptr]; j++) {
        ans += 'b';
      }
      ptr++;
      while (i > 0 && s[i-1] == '*') {
        i--;
      }
    }
    else {
      ans += 'a';
    }
  }
  reverse(ans.begin(), ans.end());
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





