#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n,k;
    cin >> n >> k;
    int t = -1;
    int c = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        c += i;
        cnt++;
        if (__builtin_popcount(c) == 1) {
            if (k >> (c - 1) & 1) {
                cout << cnt * (-t + 1) << ' ';
                t = cnt * (t - 1) - 1;
                cnt = 0;
            }
            else {
                cout << t << ' ';
            }
        }
        else {
            cout << t << ' ';
        }
    }
    cout << '\n';
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





