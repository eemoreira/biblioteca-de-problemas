#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "codes/debug.h"
#else
#define dbg(...)
#endif

/* stop freaking out pls */
void solve() {
  long long n,k;
  cin >> n >> k;
  map<int,long long> f;
  for (int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    f[a] += b;
  }
  int ans = 0;
  for (auto u : f) {
    k -= u.second;
    ans = u.first;
    if (k <= 0) {
      break;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}




