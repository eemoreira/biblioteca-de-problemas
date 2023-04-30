#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char,int> f;
  auto ch = [&](char c) {
    if (c == toupper(c)) return tolower(c);
    return toupper(c);
  };
  for (auto &u : s) {
    f[u] += 1;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    char c = i + 'a';
    int now = min(f[c], f[ch(c)]);
    ans += now;
    f[c] -= now;
    f[ch(c)] -= now;
  }
  for (int i = 0; i < 26; i++) {
    int c = i + 'a';
    int now = max(f[c] / 2, f[ch(c)] / 2);
    ans += min(k, now);
    k -= min(k, now);
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





