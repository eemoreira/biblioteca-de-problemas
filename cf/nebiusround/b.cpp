#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n,k,d,w;
    cin >> n >> k >> d >> w;
    int ans = 0;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    int ptr = 0;
    while (ptr < n) {
        int v = a[ptr] + w;
        int t = ptr;
        ans += 1;
        int cnt = 0;
        while (t < n && a[t] <= v + d) {
            cnt += 1;
            if (cnt > k) {
                v = a[t] + w;
                cnt = 1;
                ans += 1;
            }
            t += 1;
        }
        dbg(cnt, ptr);
        ptr = t;
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





