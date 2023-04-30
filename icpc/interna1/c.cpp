#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    const int mod = 1e9 + 7;
    long long ans = 0;
    vector<long long> dp(n + 1);
    for (int i = n; i >= 1; i--) {
        dp[i] = (n / i) * (n / i - 1) >> 1;
        dp[i] %= mod;
        for (int j = i << 1; j <= n; j+=i) {
            dp[i] = (dp[i] - dp[j] + mod) % mod;
        }
    }
    cout << dp[1] << '\n';
}






