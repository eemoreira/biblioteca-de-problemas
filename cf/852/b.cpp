#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int x,y;
  cin >> x >> y;
  vector<int> ans;
  for (int i = x; i > y; i--) { 
    ans.emplace_back(i);
  }
  for (int i = y; i < x; i++) {
    ans.emplace_back(i);
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " \n"[i+1 == (int)ans.size()];
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





