#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> i3;
typedef pair<ll,ll> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 1e5 + 5;
vector<ii> adj[maxn];
ll ans[maxn][12];
int n, m, k;
set<i3> pq;

void app(int v, int t, ll temp) {
    for (int i = t; i < k; i++) {
        if (ans[v][i] > temp) {
            ll now = ans[v][i];
            ans[v][i] = temp;
            pq.emplace(ans[v][i], i, v);
            app(v, i, now);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v, w);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 12; j++) {
            ans[i][j] = 1e18;
        }
    }

    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto [w, t, v] = *pq.begin();
        pq.erase(pq.begin());

        if (ans[v][t] < w) continue;
        ans[v][t] = w;
        
        for (auto [u, r] : adj[v]) {
            app(u, 0, ans[v][t] + r);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << ans[n - 1][i] << " \n"[i == k - 1];
    }
}





