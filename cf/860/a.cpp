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
    vector<int> a(n), b(n);
    for (auto &u : a) {
        cin >> u;
    }
    for (auto &u : b) {
        cin >> u;
    }
    if (n == 1) {
        cout << "yes\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i],b[i]);
        }
    }
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
        ok &= a.back() >= a[i] && b.back() >= b[i];
    }
    cout << (ok ? "yes\n" : "no\n");
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





