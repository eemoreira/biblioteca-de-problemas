#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e5 + 5;
vector<int> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    queue<int> q;
    vector<int> d(n, 1e9);
    d[0] = 0;
    q.emplace(0);

    vector<int> last(n);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.emplace(u);
                last[u] = v;
            }
        }
    }
    if (d[n - 1] < 1e9) {
        int end = n - 1;
        vector<int> ans;
        while (end) {
            ans.emplace_back(end + 1);
            end = last[end];
        }
        ans.emplace_back(1);
        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (auto u : ans) cout << u << ' ';
        cout << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}





