#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll dp[maxn];
vector<int> adj[maxn];
int n, m;

ll dfs(int v) {
    if (dp[v] != -1) return dp[v];
    dp[v] = 0;
    for (auto u : adj[v]) {
        dp[v] = (dp[v] + dfs(u)) % mod;
    }
    return dp[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) dp[i] = -1;
    dp[n - 1] = 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
    }
    cout << dfs(0) % mod << '\n';
}





