#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  const int mx = 2 << __lg(5050);
  vector<vector<int>> f(mx);
  vector<int> used(mx);
  for (int i = 0; i < n; i++) {
    f[a[i]].emplace_back(0);
  }
  used[0] = 1;
  vector<int> id(mx,mx);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (auto u : f[x]) {
      int now = x ^ u;
      used[now] = 1;
      while (id[now] > x) {
        id[now]--;
        if (id[now] != x) {
          f[id[now]].emplace_back(now);
        }
      }
    }
    f[x].clear();
  }
  int k = 0;
  for (int i = 0; i < mx; i++) {
    k += used[i];
  }
  cout << k << '\n';
  for (int i = 0; i < mx ; i++) {
    if (used[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}






