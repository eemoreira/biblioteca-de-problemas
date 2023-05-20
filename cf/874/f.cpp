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

const int mod = 1e9 + 7;

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
  return bpw(a, mod - 2);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int,int> f;
  for (auto &u : a) {
    cin >> u;
    f[u]++;
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  int ptr = 0;
  ll ans = 0;
  ll x = 1;
  for (int i = 0; i < n; i++) {
    while (ptr < n && a[i] + m > a[ptr]) {
      x = x * f[a[ptr]] % mod;
      ptr++;
    }
    if (ptr - i == m) {
      ans = (ans + x) % mod;
    }
    x = x * inv(f[a[i]]) % mod;
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





