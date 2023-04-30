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

/* stop freaking out pls */

const int maxn = 2e5 + 5;
int n, l;
int up[maxn][30], dl[maxn];
vector<int> adj[maxn];

void Pre_dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : adj[v]){
        if (u != p) {
            dl[u] = dl[v] + 1;
            Pre_dfs(u,v);
        }
    }
}

int lca(int u, int v){
    if (dl[u] < dl[v]) {
        swap(u,v);
    }
    int k = dl[u] - dl[v];
    for (int i = l; ~i; i--) {
        if (k >> i & 1) {
            u = up[u][i];
        }
    }
    if (u == v) return v;
    for (int i = l; ~i; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void preprocess(int root) {
    l =  __lg(n) + 1;
    Pre_dfs(root, root);
}

int Get_dist(int v, int u) {
    return dl[v] + dl[u] - 2 * dl[lca(u,v)];
}

vector<ll> d;
int k, c;
int L, R;

int bfs(int root) {
    queue<int> q;
    q.emplace(root);
    d = vector<ll>(n, 1e9);
    d[root] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) if (d[v] + 1 < d[u]) {
            d[u] = d[v] + 1;
            q.emplace(u);
        }
    }
    return max_element(d.begin(), d.end()) - d.begin();
}

ll ans = 0;
vector<ll> dpt;

void dfs(int v, int p) {
    ll mx = max(Get_dist(v, R), Get_dist(v, L));
    ans = max(k * mx - c * dpt[v], ans);
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
    }
}

void solve() {
    cin >> n >> k >> c;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    preprocess(0);
    L = bfs(0);
    dpt = d;
    R = bfs(L);
    ans = 0;
    dfs(0, 0);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





