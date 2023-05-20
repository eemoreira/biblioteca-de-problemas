#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<vector<ll>> mat;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mod = 1e9 + 9;

mat mul(mat& a, mat& b) {
  mat ans(3, vector<ll>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        a[i][k] %= mod;
        b[k][j] %= mod;
        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % mod + mod) % mod;
      }
    }
  }
  return ans;
}

mat bpw(mat a, ll e) {
  mat ans(3, vector<ll>(3));
  for (int i = 0; i < 3; i++) ans[i][i] = 1;
  while (e) {
    if (e & 1) ans = mul(ans, a);
    a = mul(a, a);
    e >>= 1;
  }
  return ans;
}

ll bpw(ll a, ll e) {
  ll ans = 1;
  while (e) {
    if (e & 1) ans = ans * a % mod;
    a = a * a % mod;
    e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t, n;
  cin >> t >> n;
  vector<ll> a(n);
  for (auto &u : a) cin >> u;
  ll g = (4 * t - 1) % mod;
  mat base = { 
    {1, 0, 0}, 
    {1, 0, 0}, 
    {1, 0, 0} 
  };
  mat x = {
    {(mod + 1) / 2, (mod + 1) / 2, 0},
    {((mod + 1) / 2) * (mod - g) % mod, (mod + 1) / 2, 0},
    {1, 0, 1}
  };
  sort(a.rbegin(), a.rend());
  x = bpw(x, a[0]);
  x = mul(x, base);
  ll ans = (x[2][0]%mod + mod - 1) % mod;
  x = {
    {1, 1, 0},
    {mod-g, 1, 0},
    {1, 0, 1}
  };
  for (int i = 0; i < n; i++) {
    auto now = bpw(x, a[i] - 1);
    now = mul(now, base);
    ans = (ans - bpw((mod + 1) / 2, a[i] - 1) * now[0][0] % mod + mod) % mod;
  }
  cout << ans << '\n';
}





