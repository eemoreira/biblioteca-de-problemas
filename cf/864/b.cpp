#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; 
        }
    }
    int dif = 0;
    for (int i = 0; i < (n + 1)/2; i++) {
        for (int j = 0; j < n; j++) {
            if (n % 2 && i == (n + 1)/2 - 1) {
                if (j < (n + 1)/2) {
                    dif += a[i][j] != a[n-1-i][n-1-j];
                }
            }
            else {
                dif += a[i][j] != a[n-1-i][n-1-j];
            }
        }
    }
    dbg(dif, k);
    cout << (dif <= k && (dif % 2 == k % 2 || n & 1) ? "yes\n" : "no\n");
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





