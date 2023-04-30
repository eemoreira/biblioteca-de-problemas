#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V,n,m;
    cin >> V >> n >> m;
    vector<vector<vector<long long>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u,v,t,p;
        cin >> u >> v >> t >> p;
        --u;--v;
        vector<long long> now = {t,p,v};
        adj[u].emplace_back(now);
        now[2] = u;
        adj[v].emplace_back(now);
    }
    int x,y;
    cin >> x >> y;
    --x;--y;
    multiset<vector<long long>> pq;
    vector<long long> t = {0,0,x};
    pq.emplace(t);
    vector<vector<long long>> ans(n, vector<long long>(V+1,1e18));
    while (!pq.empty()) {
        vector<long long> now = *pq.begin();
        pq.erase(pq.begin());
        if (now[1] > V || now[0] >= ans[now[2]][now[1]]) {
            continue;
        }
        ans[now[2]][now[1]] = now[0];
        for (auto u : adj[now[2]]) {
            vector<long long> w = {now[0] + u[0], now[1] + u[1], u[2]};
            pq.emplace(w);
        }
    }
    long long anss = 1e18;
    for (int i = 0; i <= V; i++) {
        anss = min(anss, ans[y][i]);
    }
    cout << (anss == 1e18 ? -1 : anss) << '\n';
}





