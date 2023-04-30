#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MAX = 6e3 + 50;
vector<pair<int,int>> ks[MAX];
int a[MAX];

long long Ks(int k) {
    int n = ks[k].size();
    vector<vector<long long>> dp(n + 1, vector<long long>(a[k] + 1, 0));
    dbg(k, ks[k], a[k]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= a[k]; j++) {
            auto [w,v] = ks[k][i-1];
            dp[i][j] = dp[i - 1][j];
            if (j - w >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
            }
        }
    }
    dbg(k, dp);
    return dp[n][a[k]];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int w, v, k;
        cin >> w >> v >> k;
        --k;
        ks[k].emplace_back(w, v);
    }
    vector<pair<int,long long>> all(n);
    for (int i = 0; i < n; i++) {
        all[i] = make_pair(a[i], Ks(i));
    }
    dbg(all);
    vector<vector<long long>> dp(n + 1, vector<long long>(p + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            auto [w,v] = all[i - 1];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j - w >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
            }
        }
    }
    cout << dp[n][p] << '\n';
}





