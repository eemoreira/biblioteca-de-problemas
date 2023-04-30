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
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        --v; --u;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<long long>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = vector<long long>((int)adj[i].size()+(i == 0));
    }
    function<void(int,int)> dfs = [&](int v, int p) {
        vector<pair<long long,long long>> got;
        for (auto u : adj[v]) {
            if (u != p) {
                dfs(u,v);
                long long mx = 0;
                long long mx1 = 0;
                for (int j = 0; j < (int)dp[u].size(); j++) {
                    assert(j + 1 < n);
                    mx = max(mx, dp[u][j] - a[j] + a[j+1]);
                    mx1 = max(mx1, dp[u][j]);
                }
                got.emplace_back(mx,mx1);
            }
        }
        dp[v][0] = a[0];
        dbg(v, dp[v][0], got);
        if (!got.empty()) {
            sort(got.begin(), got.end(), [&](pair<long long,long long> x, pair<long long,long long> y){ 
                    return x.first - x.second > y.first - y.second;
            });
            vector<long long> pre((int)got.size() + 1), suf((int)got.size() + 1);
            for (int i = 1; i <= (int)got.size(); i++) {
                pre[i] = pre[i-1] + got[i-1].first;
            }
            suf.emplace_back(0);
            for (int i = (int)got.size(); i >= 1; i--) {
                suf[i] = suf[i+1] + got[i-1].second;
            }
            dbg(pre, suf);
            for (int i = 0; i <= (int)got.size(); i++) {
                dp[v][(int)got.size()-i] = max(dp[v][(int)got.size()-i], a[(int)got.size()-i] + pre[i] + suf[i+1]);
            }
        }
    };
    dfs(0,0);
    dbg(dp);
    cout << *max_element(dp[0].begin(), dp[0].end()) << '\n';
}






