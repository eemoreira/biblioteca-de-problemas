#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> vis(n + m + 1);
  vector<int> ans(n,-1);
  int ptr = n-1;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    if (!vis[v] && ptr >= 0) {
      vis[v] = 1;
      ans[ptr--] = i+1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i+1 == n];
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





