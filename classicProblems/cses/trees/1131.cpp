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

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int n;

ii bfs(int root) {
    queue<int> q;
    q.emplace(root);
    vector<int> d(n, -1);
    d[root] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) if (d[u] == -1) {
            d[u] = d[v] + 1;
            q.emplace(u);
        }
    }
    int it = max_element(d.begin(), d.end()) - d.begin();
    return make_pair(it, d[it]);
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
    int o = bfs(0).first;
    cout << bfs(o).second << '\n';
}





