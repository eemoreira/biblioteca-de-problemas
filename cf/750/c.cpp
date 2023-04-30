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
  string s;
  cin >> n >> s;
  int l = 0, r = n-1;
  while (l <= r && s[l] == s[r]) {
    l++;
    r--;
  }
  if (l >= r) {
    cout << 0 << '\n';
    return;
  }
  auto go = [&](string t) {
    int i = 0, j = (int)t.size()-1;
    int ans = 0;
    while (i < j) {
      if (t[i] != t[j]) {
        if (t[i] != t[0] && t[j] != t[0]) {
          return -1;
        }
        if (t[i] == t[0]) {
          i++;
        }
        else {
          j--;
        }
        ans++;
      }
      else {
        i++; j--;
      }
    }
    return ans;
  };
  s = s.substr(l,r-l+1);
  int f = go(s);
  reverse(s.begin(), s.end());
  int g = go(s);
  if (f == -1 && g == -1) {
    cout << -1 << '\n';
  }
  else if (f == -1) {
    cout << g << '\n';
  }
  else if (g == -1) {
    cout << f << '\n';
  }
  else {
    cout << min(f,g) << '\n';
  }
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





