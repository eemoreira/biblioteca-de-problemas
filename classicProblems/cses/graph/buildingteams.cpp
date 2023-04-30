#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e5 + 5;
vector<int> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) continue;
        ans[i] = 0;
        queue<int> q;
        q.emplace(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (ans[u] == ans[v]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
                if (ans[u] != -1) continue;
                ans[u] = ans[v] ^ 1;
                q.emplace(u);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i]+1 << " \n"[i == n - 1];
    }
}





