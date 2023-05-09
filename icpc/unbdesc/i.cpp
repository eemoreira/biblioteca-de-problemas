#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
    // dp[i][0] -> pegar 0
    // dp[i][1] -> pegar 1
    // dp[i][2] -> pegar -1
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = dp[i-1][1] + (a[i] != 1);
        if (i > 1) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][0]) + (a[i] != 0);
        }
        if (i > 2) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][2]) + (a[i] != -1);
        }
    }
    cout << dp[n][2] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





