#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int y;
bool vis[maxn];

void dfs(int v) {
    y++;
    vis[v] = true;
    for (auto u : adj[v]) if (!vis[u]) dfs(u);
}


void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    int x = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        dfs(i);
        int grundy = (y < l + r ? y / l : 0);
        x ^= grundy;
        y = 0;
    }
    cout << (x ? "Alice\n" : "Bob\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}






