#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
// e = k, n - k - e = k
// n = 3k

// k = 1
// k = 2, (1, fodeu)
// k = 3, (1, 2)
// k = 4, (1, 3), (2, fodeu)
// k >= 5 sempre tem 2 diferente

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, e;
    cin >> n >> k >> e;
    int mn = min(e, n - k - e);
    int mx = max(e, n - k - e);
    dbg(mx, mn);
    if (mx == mn) {
        if (mx == 1) cout << (k == 1 ? 2 : 1) << '\n';
        else if (mx == 2) {
            if (k == 1) {
                cout << 2 << '\n';
            }
            else if (k == 2) {
                cout << 3 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else if (mx == 3) {
            if (k == 1) {
                cout << 1 << '\n';
            }
            else if (k == 2) {
                cout << 2 << '\n';
            }
            else if (k == 3) {
                cout << 3 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (mx == 4) {
            if (k == 1) {
                cout << 1 << '\n';
            }
            else if (k == 2) {
                cout << 0 << '\n';
            }
            else if (k == 3) {
                cout << 1 << '\n';
            }
            else if (k == 4) {
                cout << 2 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else cout << 0 << '\n';
    }
    else {
        if (e != k && n - k - e != k) {
            cout << 0 << '\n';
            return 0;
        }
        vector<vector<int>> dp(k, vector<int>(k + 1));
        int skip = mx == k ? mn : mx;
        dbg(skip);
        dp[0][0] = 1;
        int ans = 0;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] |= dp[i-1][j];
                if (j - i >= 0 && i != skip) {
                    dp[i][j] |= dp[i-1][j - i];
                }
                if (dp[i][j]) ans = max(ans, j);
            }
        }
        dbg(dp);
        cout << k - ans << '\n';
    }
}






