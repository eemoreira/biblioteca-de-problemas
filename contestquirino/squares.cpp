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

auto main() -> int32_t {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  const int mod = 998244353;
  ll ans = 0;
  ll nxt = 1;
  // (n / k + k) / 2
  for (ll i = 1; i <= n; i++) {
    ll now = (n / i + i) / 2 - i + 1;
    if (now <= 0) {
      break;
    }
    ans = (ans + now) % mod;
  }
  cout << ans << '\n';
}




