#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 1e5 + 50;
vector<int> adj[maxn];
ll ans[maxn], a[maxn], dad[maxn], s[maxn];
multiset<ii, greater<ii>> pq[maxn];

void dfs(int v, int p) {
    ans[v] = a[v];
    s[v] = 1;
    dad[v] = p;
    for (int u : adj[v]) if (u != p) {
        dfs(u, v);
        ans[v] += ans[u];
        s[v] += s[u];
        pq[v].emplace(make_pair(s[u], -u));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dad[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    dfs(0, 0);
    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int x;
            cin >> x;
            cout << ans[x - 1] << '\n';
        }
        else {
            int x;
            cin >> x;
            --x;
            if (pq[x].empty()) continue;
            auto p = *pq[x].begin();
            pq[x].erase(pq[x].begin());
            p.second = -p.second;
            ll ansp = ans[p.second];
            ll sp = s[p.second];
            if (dad[x] >= 0) {
                pq[dad[x]].erase(make_pair(s[x], -x));
            }

            ans[p.second] = ans[x];
            ans[x] -= ansp;
            s[p.second] = s[x];
            s[x] -= sp;

            pq[p.second].emplace(make_pair(s[x], -x));
            if (dad[x] >= 0) {
                pq[dad[x]].emplace(make_pair(s[p.second], -p.second));
            }

            dad[p.second] = dad[x];
            dad[x] = p.second;
        }
    }
}





