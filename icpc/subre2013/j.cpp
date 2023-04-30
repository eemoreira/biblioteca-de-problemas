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


class DSU {
public:
    vector<int> p;
    int n;
    vector<int> sz;
    DSU(int _n) : n(_n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
    inline int find(int x){
        return x == p[x] ? x : (p[x] = find(p[x]));
    }
    inline bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if (sz[y] < sz[x]) swap(y, x);
        if(x != y){
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};

const int maxn = 2e4 + 10;
const int L = __lg(maxn) + 2;
vector<ii> adj[maxn];

int dad[maxn][L];
ll dp[maxn][L];
int tin[maxn], tout[maxn];
int timer, lg;

void dfs(int v, int p, ll w) {
    dad[v][0] = p;
    dp[v][0] = w;
    tin[v] = timer++;
    for (int i = 1; i <= lg; i++) { 
        dad[v][i] = dad[dad[v][i-1]][i-1];
        dp[v][i] = min(dp[v][i-1], dp[dad[v][i-1]][i-1]);
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
    ll ans = 1e18;
    if (Anc(u, v)) return ans;
    for (int i = lg; i >= 0; i--) {
        if (Anc(dad[u][i], v)) continue;
        ans = min(ans, dp[u][i]);
        u = dad[u][i];
    }
    return min(ans, dp[u][0]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    lg = __lg(n) + 1;
    memset(dp, 0x3f, sizeof(dp));
    vector<i3> e;
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        --v; --u;
        e.emplace_back(w, v, u);
    }
    sort(e.rbegin(), e.rend());
    DSU d(n);
    for (auto [w, v, u] : e) {
        if (d.unite(v, u)) {
            adj[v].emplace_back(u, w);
            adj[u].emplace_back(v, w);
        }
    }
    dfs(0,0,(ll)1e18);
    while (q--) { 
        int u, v;
        cin >> u >> v;
        --v; --u;
        cout << min(query(u, v), query(v, u)) << '\n';
    }
}





