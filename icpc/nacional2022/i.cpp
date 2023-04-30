#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int,int>> id(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            id[a[i][j]] = {i,j};
        }
    }
    /* se isso passar eu sou maluco */
    dbg(a);
    vector<int> vis(n * m + 1);
    vector<pair<int,int>> mv = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    auto valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && !vis[a[x][y]];
    };
    set<int> pq;
    function<int(int,int)> solve = [&](int x, int y) {
        vis[a[x][y]] = 1;
        for (auto [i,j] : mv) {
            if (valid(i+x,j+y)) {
                if (a[i+x][j+y] > a[x][y]) {
                    pq.emplace(a[i+x][j+y]);
                }
            }
        }
        if (pq.empty()) return 0;
        int v = *pq.begin();
        pq.erase(pq.begin());
        if (v == a[x][y]) {
            if (pq.empty()) return 0;
            v = *pq.begin();
            pq.erase(pq.begin());
        }
        dbg(a[x][y], v);
        return 1 + solve(id[v].first, id[v].second);
    };
    int ans = 1;
    for (int i = 1; i <= n * m; i++) {
        dbg(i);
        pq.clear();
        vis.assign(n*m+1, 0);
        if (n * m - i + 1 <= ans) break;
        ans = max(ans, solve(id[i].first, id[i].second) + 1);
    }
    cout << ans << '\n';
    return 0;
}



