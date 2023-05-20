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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll now = n - i;
    ans += now * (now + 1) / 2;
  }
  dbg(ans);
  for (int i = 1; i < n; i++) {
    ll l = 0, r = 0;
    int it = i;
    while (it && a[i] >= a[it]) {
      it--;
      l++;
    }
    it = i + 1;
    while (it <= n && a[i] > a[it]) {
      it++;
    }
    while (it <= n && a[it] >= a[i]) {
      r++;
      it++;
    }
    dbg(l, r);
    ans -= l * r;
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





