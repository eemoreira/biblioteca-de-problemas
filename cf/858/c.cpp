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
    n <<= 1;
    vector<int> a(n);
    long long ans = 0;
    for (auto &u : a) {
        cin >> u;
        ans += abs(u);
    }
    if (n == 2) {
        for (int i = 0; i < n; i++) {
            long long now = 0;
            for (int j = 0; j < n; j++) {
                now += abs(a[i] - a[j]);
            }
            ans = min(ans, now);
        }
    }
    if (n % 4) {
        cout << ans << '\n';
        return;
    }
    if (n == 4) {
        long long now = 0;
        for (int i = 0; i < n; i++) {
            now += abs(2 - a[i]);
        }
        ans = min(ans, now);
    }
    long long y = 0;
    for (int i = 0; i < n; i++) {
        y += abs(-1 - a[i]);
    }
    for (int i = 0; i < n; i++) {
        ans = min(ans, y - abs(-1 -a[i]) + abs(n/2 - a[i]));
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





