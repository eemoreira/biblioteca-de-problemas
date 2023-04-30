#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int, greater<int>> pq;
  for (auto &u : a) {
    cin >> u;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      pq.emplace(a[i]);
    }
    else if (!pq.empty()) {
      ans += *pq.begin();
      pq.erase(pq.begin());
    }
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





