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
  vector<string> a(n);
  vector<vector<int>> have(n, vector<int>(26));
  vector<vector<int>> p(n, vector<int>(26));
  vector<int> masks(n);
  auto buildmask = [&](int w) {
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (p[w][i]) {
        ans |= 1 << i;
      }
    }
    return ans;
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto u : a[i]) {
      have[i][u - 'a'] += 1;
      p[i][u - 'a'] ^= 1;
    }
    masks[i] = buildmask(i);
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    map<int,int> f;
    const int mx = (1 << 26) - 1 - (1 << i);
    for (int j = 0; j < n; j++) {
      if (have[j][i]) continue;
      ans += f[masks[j] ^ mx];
      f[masks[j]] += 1;
    }
  }
  cout << ans << '\n';
}





