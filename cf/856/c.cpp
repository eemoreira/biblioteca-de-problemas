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
  int ans = 0;
  multiset<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.emplace(x);
    while (!q.empty()) {
      int t = *q.begin();
      int s = q.size();
      if (s > t) {
        q.erase(q.begin());
      }
      else {
        break;
      }
    }
    cout << q.size() << " \n"[i + 1 == n];
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





