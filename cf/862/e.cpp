#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int a[maxn];
pair<int,int> edg[maxn];
map<pair<int,int>, int> ans;
map<int,int> f, tot;

void dfs(int v, int p, int mx) {
    for (auto u : adj[v]) if (u != p) { 
        dfs(u, v, mx);
    }
    if (v != p) {
        if (a[v] > mx && f[a[v]] > 1) {
            mx = a[v];
        }
        if (a[v] > mx && abs(f[a[v]] - tot[a[v]]) > 1) {
            mx = a[v];
        }
    }
    ans[make_pair(min(v, p), max(v, p))] = mx;
    f[a[v]]++;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
        if (v > u) swap(v, u);
        edg[i-1] = {v, u};
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot[a[i]]++;
    }
    dbg(tot);
    dfs(0, 0, 0);
    for (int i = 0; i < n - 1; i++) {
        cout << ans[edg[i]] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





