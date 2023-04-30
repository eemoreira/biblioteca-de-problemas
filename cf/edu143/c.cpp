#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

#define int long long

void solve() {
  int n;
  cin >> n;
	vector<long long> a(n);
  for (int i = 0; i < n; i++) {
		cin >> a[i];
  }
  vector<long long> b(n);
  for (auto &u : b) {
    cin >> u;
  }
	vector<long long> p(n+1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i-1] + b[i-1];
	}
	vector<long long> sub(n+5), got(n+5);
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n;
		int f = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[mid] - p[i] <= a[i]) {
				l = mid + 1;
				f = mid;
			}
			else {
				r = mid - 1;
			}
		}
		got[f] += a[i] - (p[f] - p[i]);
		sub[f]++;
	}
	int g = 0;
	dbg(got,sub);
	for (int i = 0; i < n; i++) {
		g += sub[i];
		long long ans = b[i] * (i - g + 1);
		ans += got[i];
		cout << ans << " \n"[i+1 == n];
	}
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





