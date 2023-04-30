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
vector<int> go;
vector<vector<int>> ans;

void dfs(int v, int p) {
    go.emplace_back(v);
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
    }
    if (!go.empty()) ans.emplace_back(go);
    go.clear();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    vector<int> dad(n, -1);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        --p;
        dad[i] = p;
        adj[p].emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (dad[i] == i) {
            dfs(i, i);
            break;
        }
    }
    cout << ans.size() << '\n';
    for (auto &u : ans) {
        cout << u.size() << '\n';
        for (auto x : u) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    ans.clear();
    cout << '\n';
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





