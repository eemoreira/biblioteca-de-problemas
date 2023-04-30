#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n, m;
  cin >> n >> m;
  cout << n * m << '\n';
  vector<vector<long long>> a(n, vector<long long>(m));
  int wtf = 1;
  for (int i = 0; i < m; i++) {
    a[0][i] = wtf;
    wtf += 2;
  }
  wtf = 0;
  for (int i = 0; i < m; i++) {
    a[1][i] = wtf;
    wtf += 2;
  }
  for (int i = 2; i < n; i++) {
    a[i][0] = a[i-1].back() + 4LL * m;
    for (int j = 1; j < m; j++) {
      long long x = a[i-1][j-1] ^ a[i-1][j] ^ a[i][j-1];
      a[i][j] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
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







