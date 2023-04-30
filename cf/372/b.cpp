#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

#define int long long
/* stop freaking out pls */

long long n,m,L,s,t;
vector<pair<int,int>> adj[1005];

long long ans[1005][1005];
pair<int,int> last[1005][1005];
typedef tuple<int,int,int> i3;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> L >> s >> t;
    vector<vector<long long>> ed;
    map<pair<int,int>, int> P;
    for (int i = 0; i < m; i++) {
        int v,u,w;
        cin >> v >> u >> w;
        adj[v].emplace_back(u,w);
        adj[u].emplace_back(v,w);
        vector<long long> now = {v, u, w};
        ed.emplace_back(now);
        P[make_pair(min(u,v), max(u,v))] = w;
    }
    multiset<i3> pq;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans[i][j] = 1e18;
            last[i][j] = make_pair(-1,-1);
        }
    }
    pq.emplace(0, s, 0);
    while (!pq.empty()) {
        auto [W, v, z] = *pq.begin();
        pq.erase(pq.begin());
        if (W > ans[v][z]) continue;
        ans[v][z] = W;
        for (auto [u,w] : adj[v]) {
            if (ans[u][z + (w == 0)] > w + ans[v][z]) {
                pq.emplace(ans[v][z] + w, u, z + (w == 0));
                ans[u][z + (w == 0)] = ans[v][z] + w;
                last[u][z + (w == 0)] = make_pair(v, z);
            }
        }
    }
    if (ans[t][0] < L) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        if (ans[t][i] + i <= L) {
            dbg(t, i, ans[t][i]);
            cout << "YES\n";
            int qntZeros = i;
            int v = t;
            long long val = L - ans[t][i] - i + 1;
            bool change = true;
            while (v != s) {
                dbg(v, last[v][qntZeros].first);
                int x = min(v, last[v][qntZeros].first);
                int y = max(v, last[v][qntZeros].first);
                if (P[make_pair(x,y)] == 0) {
                    if (change) {
                        P[make_pair(x,y)] = val;
                        change = false;
                    }
                    else {
                        P[make_pair(x,y)] = 1;
                    }
                }
                int l = qntZeros;
                qntZeros = last[v][qntZeros].second;
                v = last[v][l].first;
            }
            for (auto u : ed) {
                int x = u[0];
                int y = u[1];
                if (x > y) swap(x,y);
                cout << x << ' ' << y << ' ' << (P[make_pair(x,y)] == 0 ? (long long)1e18 : P[make_pair(x,y)]) << '\n';
            }
            return 0;
        }
    }
    cout << "NO\n";
}




