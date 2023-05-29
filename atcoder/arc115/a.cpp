#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
auto solve() -> void {
  int n, m;
  cin >> n >> m;
  vector<ll> p(2);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      cnt += s[j] - '1';
    }
    p[cnt & 1]++;
  }
  cout << p[0] * p[1] << '\n';
}

auto main() -> int32_t {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





