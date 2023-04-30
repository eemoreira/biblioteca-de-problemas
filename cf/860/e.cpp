#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n, 2);
    for (auto &u : a) {
        cin >> u;
    }
    vector<int> dp(n + 1);
    vector<int> f(n + 1);
    vector<int> suf(n + 1);
    for (int i = n - 1; i ; i--) {
        if (i + a[i] + 1 <= n && ~dp[i + a[i] + 1]) {
            dp[i] = dp[i + a[i] + 1] + 1;
        }
        else {
            dp[i] = -1;
        }
        suf[i] = max(suf[i + 1], dp[i + 1]);
        if (i + a[i] + 1 <= n) {
            f[i] = max(f[i + a[i] + 1] + 1, suf[i] + 1);
        }
        else {
            f[i] = suf[i] + 1;
        }
        if (a[i-1] == dp[i]) {
            ans[i-1] = 0;
        }
        else if (~dp[i] || f[i] >= a[i - 1]) {
            ans[i-1] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " \n"[i + 1 == n - 1];
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





