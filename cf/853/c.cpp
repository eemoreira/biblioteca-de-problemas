#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long now = 0;
  vector<int> f(n + q + 10, -1), add(n + q + 10);
  for (int i = 0; i < n; i++) {
    f[a[i]] = 0;
  }
  long long ans = 0;
  vector<int> last(n);
  for (int i = 1; i <= q; i++) {
    int id,v;
    cin >> id >> v;
    --id;
    if (v != a[id] && f[v] == -1) {
      now += i - add[v];
      now -= last[id];
      last[id] = i - add[v];
      f[v] = i;
      dbg(i,a[id], f[a[id]], v, add[v]);
      add[a[id]] += i - f[a[id]];
      f[a[id]] = -1;
    }
    dbg(now);
    a[id] = v;
    ans += now + 1LL * n * i;
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





