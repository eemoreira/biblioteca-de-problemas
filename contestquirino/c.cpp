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
  vector<int> cnt(31);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 31; j++) {
      cnt[j] += a[i] >> j & 1;
    }
  }
  int look = 0;
  for (int i = 0; i < 31; i++) {
    if (cnt[i] >= (n + 1) / 2) {
      look += 1 << i;
    }
  }
  int !odeia = 0;
  cout << ans << '\n';
}





