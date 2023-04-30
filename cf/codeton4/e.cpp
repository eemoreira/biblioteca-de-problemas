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
bool used[maxn];
int c;

void check(int v) {
    used[v] = true;
    for (auto u : adj[v]) if (!used[u]) {
        check(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    c = 0;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        used[i] = false;
    }
    int mx = 0;
    for (auto &u : a) {
        cin >> u;
        mx = max(mx, u);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    for (int i = 0; i < n; i++) if (!used[i]) {
        c++;
        check(i);
    }
    if (c > 1) {
        cout << "no\n";
        return;
    }
    bool ok = false;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !a[i]) {
            vis[i] = 1;
            set<pair<int,int>> pq;
            map<int,int> now;
            int cnt = 0;
            pq.emplace(a[i], i);
            while (!pq.empty() && cnt < mx) {
                auto t = *pq.begin();
                int w = t.first;
                now[t.second] = 1;
                if (w <= cnt) {
                    vis[t.second] = 1;
                    cnt++;
                    pq.erase(pq.begin());
                    for (auto u : adj[t.second]) if (!now[u]) {
                        pq.emplace(a[u], u);
                    }
                }
                else break;
            }
            dbg(cnt, i);
            if (cnt >= mx) {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "yes\n" : "no\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}





