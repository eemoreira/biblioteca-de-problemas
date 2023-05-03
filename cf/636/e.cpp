#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
vector<int> adj[maxn];

int n, m, a, b, c;

vector<int> bfs(int s) {
    queue<int> q;
    q.emplace(s);
    vector<int> d(n, 1e9);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) if (d[u] > d[v] + 1) {
            d[u] = d[v] + 1;
            q.emplace(u);
        }
    }
    return d;
}

void solve() {
    cin >> n >> m >> a >> b >> c;
    --a; --b; --c;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    vector<ll> p(m);
    for (auto &u : p) cin >> u;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    sort(p.begin(), p.end());
    vector<ll> pre(m + 1);
    for (int i = 1; i <= m; i++) {
        pre[i] = pre[i-1] + p[i-1];
    }
    vector<int> distA, distB, distC;
    distA = bfs(a);
    distB = bfs(b);
    distC = bfs(c);
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        int x = distA[i] + distB[i] + distC[i];
        if (x > m) continue;
        ans = min(ans, pre[x] + pre[distB[i]]);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}





