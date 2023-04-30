#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

typedef long long ll;
#define ll int
typedef tuple<ll,int,int> i3;
typedef pair<int,ll> ii;

/* stop freaking out pls */

const int maxn = 2e5 + 5;
const int L = __lg(maxn) + 2;
int dad[maxn][L];
ll dp[maxn][L];
int tin[maxn], tout[maxn], timer;
vector<ii> adj[maxn];
int l;

struct DSU {
    vector<int> p, sz;
    int n;
    DSU(int _n) : n(_n) {
        p = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    inline int find(int v) {
        return v == p[v] ? v : (p[v] = find(p[v]));
    }
    inline bool unite(int v, int u) {
        v = find(v);
        u = find(u);
        if (sz[v] < sz[u]) swap(v, u);
        if (v != u) {
            p[u] = v;
            sz[v] += sz[u];
            sz[u] = 0;
            return true;
        }
        return false;
    }
};


void dfs(int v, int p, ll w) {
    dad[v][0] = p;
    dp[v][0] = w;
    tin[v] = timer++;
    for (int i = 1; i <= l; i++) {
        dad[v][i] = dad[dad[v][i-1]][i-1];
        dp[v][i] = max(dp[v][i-1], dp[dad[v][i-1]][i-1]);
    }
    for (auto [u, ww] : adj[v]) if (u != p) {
        dfs(u, v, ww);
    }
    tout[v] = timer++;
}

bool Anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

ll query(int v, int u) {
    ll ans = 0;
    if (Anc(u, v)) return ans;
    for (int i = l; i >= 0; i--) {
        if (Anc(dad[u][i], v)) continue;
        ans = max(ans, dp[u][i]);
        u = dad[u][i];
    }
    return max(ans, dp[u][0]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    l = __lg(n) + 1;
    vector<i3> e;
    vector<map<int,int>> f(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        --v; --u;
        e.emplace_back(w, v, u);
        if (v > u) swap(u, v);
        f[v][u] = w;
    }
    sort(e.begin(), e.end(), [&](i3 a, i3 b) { return get<0>(a) < get<0>(b);});
    DSU d(n);
    ll ans = 0;
    for (auto [w, v, u] : e) {
        if (d.unite(v, u)) {
            adj[v].emplace_back(u, w);
            adj[u].emplace_back(v, w);
            ans += w;
            if (v > u) swap(u, v);
            f[v][u] = -1;
        }
    }
    dfs(0, 0, 0);
    int q;
    cin >> q;
    while (q--) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        if (v > u) swap(v, u);
        if (f[v][u] == -1) {
            cout << ans << '\n';
            continue;
        }
        cout << ans + f[v][u] - max(query(v, u), query(u, v)) << '\n';
    }
}





