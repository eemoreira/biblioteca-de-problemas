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
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    long long all = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            all -= a[i];
        }
        else {
            all += a[i];
        }
    }
    cout << (all > 0 ? "yes\n" : "no\n");
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





