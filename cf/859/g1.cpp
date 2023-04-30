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
    vector<long long> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    bool ok = a[0] == 1;
    long long sum = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > sum) {
            ok = false;
            break;
        }
        sum += a[i];
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





