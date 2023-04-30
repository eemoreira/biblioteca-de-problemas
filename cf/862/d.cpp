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

const int maxn = 1e5 + 5;
int ans[maxn];
int n;
vector<int> adj[maxn], d;

int bfs(int v) {
    queue<int> q;
    d.assign(n, -1);
    q.emplace(v);
    d[v] = 0;
    int ret = 0;
    int dt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto u : adj[x]) {
            if (d[u] == -1 || d[u] > d[x]) {
                d[u] = d[x] + 1;
                q.emplace(u);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] > dt) {
            dt = d[i];
            ret = i;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    int o = bfs(0);
    int e = bfs(o);
    vector<int> p, g;
    p = d;
    bfs(e);
    g = d;
    ans[1] = 1;
    for (int i = 0; i < n; i++) {
        if (i == o) continue;
        ans[max(p[i],g[i]) + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << " \n"[i == n];
    }
}






