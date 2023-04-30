#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */

map<vector<vector<int>>, long long> dp, vis;
vector<vector<int>> start(2, vector<int>(4));
vector<vector<int>> e(2, vector<int>(4));
vector<pair<int,int>> mv = {{0,1}, {1,0}};

bool valid(int i, int j) {
    return i >= 0 && i < 2 && j >= 0 && j < 4;
}

// TIRA O DEBUG
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> start[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> e[i][j];
        }
    }
    multiset<pair<long long, vector<vector<int>>>> q;
    q.emplace(0,start);
    dp[start] = 0;
    while (!q.empty()) {
        auto t = *q.begin();
        q.erase(q.begin());
        vector<vector<int>> a = t.second;
        long long p = t.first;
        if (p > dp[a]) continue;
        for (int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                for (auto u : mv) {
                    int x = u.first;
                    int y = u.second;
                    if (valid(i + x, j + y)) {
                        long long cost = a[i][j] + a[i + x][j + y];
                        swap(a[i][j], a[i + x][j + y]);
                        /* dbg(vis[nxt], nxt, a); */
                        if (!dp.count(a)) dp[a] = 1e18;
                        if (p + cost < dp[a]) {
                            dp[a] = p + cost;
                            if (a != e) {
                                q.emplace(dp[a],a);
                            }
                        }
                        swap(a[i][j], a[i + x][j + y]);
                    }
                }
            }
        }
    }
    cout << dp[e] << '\n';
}





