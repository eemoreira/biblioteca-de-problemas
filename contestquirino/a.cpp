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

// ncr(a + b, a) = ncr(a + b - 1, a - 1) + ncr(a + b - 1, a)  ? 

// f[a + b] / (f[b] * f[a]) = f[a + b - 1] / (f[b] * f[a - 1]) + f[a + b - 1] / (f[b - 1] * f[a])
// f[a + b] / (f[b] * f[a]) = a * f[a + b - 1] / (f[b] * f[a]) + b * f[a + b - 1] / (f[b] * f[a])
// f[a + b] = a * f[a + b - 1] + b * f[a + b - 1]
// f[a + b] = (a + b) * f[a + b - 1]
// qed (omg)

const int mod = 998244353;

ll bpw(ll a, ll e) {
  ll ans = 1;
  while (e) {
    if (e & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
    e >>= 1;
  }
  return ans;
}

ll inv(ll a) {
  return bpw(a, mod - 2) % mod;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll f = 1;
  for (int i = 2; i <= n; i++) f = f * i % mod;
  ll twof = f;
  for (int i = n + 1; i <= 2 * n; i++) twof = twof * i % mod;
  cout << twof * inv(f) % mod * inv(f) % mod * ((mod + 1) / 2) % mod << '\n';
}





