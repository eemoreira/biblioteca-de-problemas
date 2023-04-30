#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 1005;
string a[maxn];
int n, m;
vector<pair<int,int>> mv = {{1,0},{-1,0},{0,1},{0,-1}};
set<pair<int,int>> ms;
int vis[maxn][maxn];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

void app() {
    vector<pair<int,int>> add; 
    vector<pair<int,int>> remove;
    for (auto [x, y] : ms) {
        int cnt = 0;
        for (auto [i, j] : mv) {
            if (valid(x + i, y + j)) {
                cnt++;
                vis[x + i][y + j] = 1;
                add.emplace_back(x + i, y + j);
            }
        }
        if (cnt == 0) remove.emplace_back(x, y);
    }
    for (auto u : add) {
        ms.emplace(u);
    }
    for (auto u : remove) {
        ms.erase(u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<int,int> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M') {
                ms.emplace(i, j);
                vis[i][j] = 1;
            }
            else if (a[i][j] == '#') {
                vis[i][j] = 1;
            }
            else if (a[i][j] == 'A') {
                s = {i, j};
            }
        }
    }
    map<pair<int,int>, pair<int,int>> last;
    map<pair<int,int>, char> dir, gt;
    dir[make_pair(1, 0)] = 'D';
    dir[make_pair(-1, 0)] = 'U';
    dir[make_pair(0, 1)] = 'R';
    dir[make_pair(0, -1)] = 'L';

    set<i3> pq;
    pq.emplace(0, s.first, s.second);

    int cnt = 0;
    while (!pq.empty()) {
        auto [d, x, y] = *pq.begin();
        pq.erase(pq.begin());
        if (vis[x][y]) continue;
        vis[x][y] = 2;
        if (d > cnt || d == 0) {
            app();
            cnt++;
        }
        for (auto [i, j] : mv) {
            if (valid(x + i, y + j)) {
                last[make_pair(x + i, y + j)] = make_pair(x, y);
                gt[make_pair(x + i, y + j)] = dir[make_pair(i, j)];
                pq.emplace(d + 1, x + i, y + j);
            }
        }
    }

    auto print = [&](int x, int y) {
        if (vis[x][y] != 2) return false;
        pair<int,int> end = {x, y};
        string ans;
        while (end != s) {
            ans += gt[end];
            end = last[end];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (print(i, 0)) return 0;
        if (print(i, m-1)) return 0;
    }
    for (int i = 0; i < m; i++) {
        if (print(0, i)) return 0;
        if (print(n-1, i)) return 0;
    }
    cout << "NO\n";
}





