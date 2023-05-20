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

const int mod = 1e9 + 9;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  ll d = 1;
  ll ans = 0;
  const ll N = (1ll << n) - 1;
  for (int i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;
    int now = 0;
    if ((x & -x) > (y &-y)) {
      swap(x, y);
    }
    if (x == 0) {
      while (y) {
        y = (y << 1) & N;
        now++;
      }
    }
    else {
      while ((x & -x) < (y & -y)) { 
        x = (x << 1) & N;
        now++;
      }
      x &= N;
      dbg(x, y);
      while (x != y) {
        x = (x << 1) & N;
        y = (y << 1) & N;
        now += 2;
      }
    }
    dbg(now);
    ans = (ans + 1ll * now * d % mod) % mod;
    d = d * n % mod;
  }
  cout << ans << '\n';
}





