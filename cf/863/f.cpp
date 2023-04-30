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

const int maxn = 2e5 + 50;
vector<int> adj[maxn];
map<ll,int> check;
int k;

int cnt;
int vis[maxn];
bool t = true;
set<int> lol;

void dfs(int v, int y) {
    if ((int)adj[v].size() != y) {
        return;
    }
    vis[v]++;
    cnt++;
    for (auto u : adj[v]) {
        if ((int)adj[u].size() != y) lol.emplace(u);
        if (!vis[u]) {
            dfs(u, y);
        }
    }
}

void LOL(int v) {
    vis[v]++;
    cnt++;
    for (auto u : adj[v]) if (!vis[u]) {
        LOL(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        vis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    LOL(0);
    if (cnt < n || !check[n]) {
        cout << "no\n";
        return;
    }
    for (int i = 0; i < n; i++) vis[i] = 0;
    cnt = 0;
    k = sqrt(n);
    assert(k * k == n);
    bool ok = true;
    int f1 = 0, f2 = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        if (vis[i]) continue;
        lol.clear();
        if ((int)adj[i].size() == 2) {
            dfs(i, 2);
            ok &= cnt == k - 1 && (int)lol.size() <= 1;
            if (ok) f1++;
        }
        else if ((int)adj[i].size() == 4) {
            dfs(i, 4);
            ok &= cnt == k;
            if (ok) f2++;
        }
        else {
            ok = false;
        }
        dbg(i, (int)adj[i].size(), (int)lol.size());
    }
    dbg(f1, f2);
    ok &= f1 == k && f2 == 1;
    cout << (ok ? "yes\n" : "no\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 3; i < maxn; i++) {
        check[i * i] = 1;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





