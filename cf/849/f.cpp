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
  set<int> hard;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] / 10) {
      hard.emplace(i+1);
    }
  }
  auto go = [&](int x) {
    int ans = 0;
    while (x) {
      ans += x%10;
      x /= 10;
    }
    return ans;
  };
  while (q--) {
    int id;
    cin >> id;
    if (id == 1) {
      int l,r;
      cin >> l >> r;
      auto lb = hard.lower_bound(l);
      if (lb == hard.end()) {
        continue;
      }
      vector<int> remove;
      while (*lb <= r && lb != hard.end()) {
        int i = *lb - 1;
        a[i] = go(a[i]);
        if (!(a[i] / 10)) {
          remove.emplace_back(*lb);
        }
        lb++;
      }
      for (auto u : remove) {
        hard.erase(u);
      }
    }
    else {
      int i;
      cin >> i;
      cout << a[i-1] << '\n';
    }
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





