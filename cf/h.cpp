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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(64));
    const int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) dp[i][a[i]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << 6; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i][j]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 1 << 6; i++) {
        if (__builtin_popcount(i) == k) {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    cout << (ans * (mod + 1) / 2) % mod << '\n';
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





