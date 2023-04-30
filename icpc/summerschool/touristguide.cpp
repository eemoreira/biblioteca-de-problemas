#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> i3;
typedef pair<ll,ll> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

struct DSU {
    vector<int> p;
    vector<int> sz;
    int n;
    DSU(int _n) : n(_n) {
        p = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    };

    inline int find(int v) {
        return v == p[v] ? v : (p[v] = find(p[v]));
    }

    inline bool unite(int v, int u) {
        v = find(v);
        u = find(u);
        if (v != u) {
            if (sz[v] < sz[u]) swap(v, u);
            p[u] = v;
            sz[v] += sz[u];
            sz[u] = 0;
            return true;
        }
        return false;
    }
};

vector<i3> edges;
const int maxn = 105;
vector<ii> adj[maxn];

ll ans = 1e18;

void dfs(int dest, int v, int p, ll mn = 1e18) {
    if (dest == v) {
        ans = mn;
        return;
    }
    for (auto [u, w] : adj[v]) if (u != p) {
        dfs(dest, u, v, min(mn, w));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int vaisefude = 0;
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cout << "Scenario #" << ++vaisefude << '\n';
        ans = 1e18;
        edges.clear();
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            ll v, u, w;
            cin >> v >> u >> w;
            --v; --u;
            edges.emplace_back(-w, u, v);
        }
        DSU d(n);
        sort(edges.begin(), edges.end());
        for (auto [w, v, u] : edges) {
            if (d.find(v) != d.find(u)) {
                adj[v].emplace_back(u, -w);
                adj[u].emplace_back(v, -w);
                d.unite(v, u);
            }
        }
        int v, u;
        ll w;
        cin >> v >> u >> w;
        --v; --u;
        dfs(u, v, v);
        ans--;
        cout << "Minimum Number of Trips = " << (w + ans - 1) / ans << '\n' << '\n';
    }
}





