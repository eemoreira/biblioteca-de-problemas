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
  int n, k;
  cin >> n >> k;
  vector<ii> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (auto &u : b) {
    cin >> u;
  }
  sort(b.begin(), b.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[a[i].second] = b[i];
  }
  for (auto u : ans) {
    cout << u << ' ';
  }
  cout << '\n';
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





