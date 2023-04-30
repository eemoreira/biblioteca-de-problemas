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
    for (auto &u : a) {
        cin >> u;
    }
    bool ok = true;
    for (int i = 0; i < 1 << n; i++) {
        if (__builtin_popcount(i) != n / 2) continue;
        int m = 1;
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                m *= a[j];
            }
            else {
                s += a[j];
            }
        }
        dbg(m, s);
        ok &= m == s;
    }
    dbg(ok);
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





