#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MAX = 5e5 + 5;
long long a[MAX];
int n;

void solve() {
    int m;
    cin >> m;
    vector<long long> p(m);
    for (auto &u : p) {
        cin >> u;
        --u;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long mx = 0;
        int ptr = i;
        for (int j = p[i]; j < n; j++) {
            mx = max(mx, a[j]);
            if (ptr < m && j == p[ptr]) {
                ans += mx;
                ptr++;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}






