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

const int maxn = 5005;
i3 ed[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        ed[i] = i3(u, v, w);
    }
    vector<ll> d(n);
    d[0] = 0;
    vector<int> last(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [v, u, w] = ed[j];
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                last[u] = v;
            }
        }
    }
    dbg(d);
    for (int i = 0; i < m; i++) {
        auto [v, u, w] = ed[i];
        if (d[v] != 1e18 && d[v] + w < d[u]) {
            vector<int> ans;
            map<int,int> vis;
            int end = last[v];
            cout << "YES\n";
            while (!vis[end]) {
                dbg(end);
                vis[end] = 1;
                ans.emplace_back(end + 1);
                end = last[end];
            }
            ans.emplace_back(end + 1);
            reverse(ans.begin(), ans.end());
            for (auto x : ans) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}





