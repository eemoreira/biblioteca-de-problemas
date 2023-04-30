#include <bits/stdc++.h>
 
using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
 
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
bool vis[maxn];
map<int,int> last, f;
bool ok = false;
int use;
 
void dfs(int v, int d) {
    if (ok) return;
    vis[v] = 1;
    f[v] = d;
    for (auto u : adj[v]) if (!vis[u]) {
        last[u] = v;
        dfs(u, d + 1);
    }
    for (auto u : adj[v]) {
        if (f.count(u) && d - f[u] >= 1) {
            use = u;
            last[use] = v;
            ok = true;
            return;
        }
    }
    f.erase(v);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        adj[u].emplace_back(v);
    }
    for (int i = 0; i < n; i++) if (!vis[i]) {
        last.clear();
        f.clear();
        use = 0;
        ok = false;
        f[i] = 0;
        dfs(i, 0);
        dbg(i);
        if (ok) {
            dbg(last);
            vector<int> ans;
            map<int,int> l;
            int end = last[use];
            while (!l[end] || !last.count(end)) {
                dbg(end);
                ans.emplace_back(end + 1);
                l[end] = 1;
                end = last[end];
            }
            ans.emplace_back(end + 1);
            reverse(ans.begin(), ans.end());
            map<int, int> g;
            dbg(ans);
            for (int j = 0; j < (int)ans.size(); j++) {
                if (g.count(ans[j])) {
                    int ptr = g[ans[j]];
                    cout << j - ptr + 1 << '\n';
                    while (ptr <= j) {
                        cout << ans[ptr++] << ' ';
                    }
                    cout << '\n';
                    return 0;
                }
                g[ans[j]] = j;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
