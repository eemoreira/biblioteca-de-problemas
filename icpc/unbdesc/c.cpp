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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            int w = 2 * j - 1;
            if (i - w >= 0) {
                dp[i][j] += dp[i - w][j - 1];
            }
        }
    }
    cout << dp[n][n] << '\n';
}





