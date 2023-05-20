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
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x & 1].emplace_back(x);
  }
  sort(a[0].begin(), a[0].end());
  sort(a[1].begin(), a[1].end());
  if (a[1].empty() || a[0].empty()) {
    cout << "yes\n";
  }
  else if (a[1][0] < a[0][0]) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
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





