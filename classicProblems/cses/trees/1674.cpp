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
ll sz[maxn];

void dfs(int v, int p) {
    sz[v] = 0;
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
        sz[v] += sz[u] + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;
        adj[p].emplace_back(i);
        adj[i].emplace_back(p);
    }
    dfs(0,0);
    for (int i = 0; i < n; i++) cout << sz[i] << " \n"[i == n - 1];
}





