#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e5 + 5;
vector<ii> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> v >> u >> w;
        --u; --v;
        adj[v].emplace_back(u, w);
    }
    set<ii> pq;
    pq.emplace(0, 0);
    vector<ll> d(n, 1e18);
    d[0] = 0;
    
    while (!pq.empty()) {
        auto [v, w] = *pq.begin();
        pq.erase(pq.begin());
        if (w > d[v]) continue;
        d[v] = w;
        for (auto [x, y] : adj[v]) {
            if (d[v] + y <= d[x]) {
                d[x] = d[v] + y;
                pq.emplace(x, d[x]);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
}





