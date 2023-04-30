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
  vector<int> f(26);
  int lol = 2;
  for (int i = 0; i < 26; i+=3) {
      dbg(i);
      for (int j = i; j < i + 3; j++) {
          f[j] = lol;
      }
      if (char(i+'a') == 'p') {
          f[i + 3] = lol;
          i++;
      }
      else if (char(i+'a') == 'w') {
          f[i + 3] = lol;
          break;
      }
      lol++;
  }
  dbg(f);
  int n,q;
  cin >> n >> q;
  map<string, int> ans;
  for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      string now = "";
      for (auto u : s) {
          now += char(f[u-'a'] + '0');
      }
      ans[now]++;
  }
  while (q--) {
      string s;
      cin >> s;
      cout << ans[s] << '\n';
  }
}





