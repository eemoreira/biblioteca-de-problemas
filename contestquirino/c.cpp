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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<int> cnt(31);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 31; j++) {
      cnt[j] += a[i] >> j & 1;
    }
  }
  ll ans = 0;
  a.emplace_back(0);
  for (int i = 0; i <= n; i++) {
    ll now = 0;
    for (int j = 0; j < 31; j++) {
      if (a[i] >> j & 1) {
        now += (n - cnt[j]) * (1ll << j);
      }
      else {
        now += cnt[j] * (1ll << j);
      }
    }
    ans = max(ans, now);
  }
  cout << ans << '\n';
}





