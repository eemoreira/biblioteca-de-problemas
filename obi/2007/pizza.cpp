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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  bool ok = true;
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> pmx(n + 1), sufmx(n + 2), ps(n + 1), sufs(n + 2), pmn(n + 1), sufmn(n + 2);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + a[i - 1];
    pmx[i] = max(pmx[i - 1], ps[i]);
    pmn[i] = min(pmn[i - 1], ps[i]);
  }
  for (int i = n; i >= 1; i--) {
    sufs[i] = sufs[i + 1] + a[i - 1];
    sufmx[i] = max(sufmx[i + 1], sufs[i]);
    sufmn[i] = min(sufmn[i + 1], sufs[i]);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, pmx[i] + sufmx[i + 1]);
    ans = max(ans, ps[n] - pmn[i] - sufmn[i + 1]);
  }
  cout << ans << '\n';
}


