#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int r,c;
    cin >> r >> c;
    vector<string> a(r);
    for (auto &u : a) {
        cin >> u;
    }
    deque<pair<int,int>> dq;
    vector<pair<int,int>> mv = {{0,1},{1,0},{0,-1},{-1,0}};
    auto valid = [&](int x, int y) {
        return x >= 0 && x < r && y >= 0 && y < c;
    };
    vector<vector<int>> ans(r, vector<int>(c,1e9));
    dq.emplace_back(0,0);
    ans[0][0] = 0;
    while (!dq.empty()) {
        int i = dq.front().first;
        int j = dq.front().second;
        char ch = a[i][j];
        dq.pop_front();
        for (auto [x,y] : mv) {
            if (valid(i + x, j + y)) {
                if (a[i + x][j + y] == ch && ans[i + x][j + y] > ans[i][j]) {
                    dq.emplace_front(i + x, j + y);
                    ans[i + x][j + y] = ans[i][j];
                }
                if (a[i + x][j + y] != ch && ans[i + x][j + y] > ans[i][j] + 1) {
                    dq.emplace_back(i + x, j + y);
                    ans[i + x][j + y] = ans[i][j] + 1;
                }
            }
        }
    }
    cout << ans[--r][--c] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





