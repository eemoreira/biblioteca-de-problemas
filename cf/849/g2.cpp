#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
  int n,c;
  cin >> n >> c;
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i] = {min(v+i+1, v+n-i), v+i+1};
  }
  sort(a.begin(),a.end());
  vector<long long> p(n+1);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i-1] + a[i-1].first; 
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second <= c) {
      ans = max(ans,1);
      int t = c;
      t -= a[i].second;
      int l = 1, r = n;
      while (l <= r) {
        int mid = (l+r) >> 1;
        long long sum = p[mid] - (mid >= i+1 ? a[i].first : 0);
        if (sum <= t) {
          ans = max(mid < i+1 ? mid+1 : mid, ans);
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }
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





