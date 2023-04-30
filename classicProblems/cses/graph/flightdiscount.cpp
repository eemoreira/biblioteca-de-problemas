#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> i3;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 1e5 + 5;
vector<ii> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v, w);
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 1e18));
    dp[0][0] = dp[0][1] = 0;
    set<i3> pq;
    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        auto [w, f, v] = *pq.begin();
        pq.erase(pq.begin());
        if (dp[v][f] < w) continue;
        dp[v][f] = w;
        for (auto [u, t] : adj[v]) {
            if (f == 0) {
                if (dp[v][0] + (t >> 1) < dp[u][1]) {
                    dp[u][1] = dp[v][0] + (t >> 1);
                    pq.emplace(dp[u][1], 1, u);
                }
            }
            if (dp[v][f] + t < dp[u][f]) {
                dp[u][f] = dp[v][f] + t;
                pq.emplace(dp[u][f], f, u);
            }
        }
    }
    dbg(dp);
    cout << dp[n - 1][1] << '\n';
}





