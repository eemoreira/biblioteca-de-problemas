#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjESQ(n + 1);
    for (int i = 0; i < n; i++) {
        int v,l,center;
        cin >> v >> l >> center;
        adjESQ[v].emplace_back(l);
        adjESQ[v].emplace_back(center);
    }
    int m;
    cin >> m;
    vector<vector<int>> adjDIR(m + 1);
    for (int i = 0; i < m; i++) {
        int v,center,r;
        cin >> v >> center >> r;
        adjDIR[v].emplace_back(r);
        adjDIR[v].emplace_back(center);
    }
    int ans1,ans2;
    ans1 = ans2 = 0;
    function<void(int,int,int)> dfs = [&](int v, int cnt, int wht) {
        int y = 0;
        if (v == 0) return;
        if (wht == 0) ans1 = max(ans1, cnt);
        else ans2 = max(ans2, cnt);
        if (wht == 0) {
            for (auto u : adjESQ[v]) {
                dfs(u, y == 0 ? 1 : cnt + 1, wht);
                y++;
            }
        }
        else {
            for (auto u : adjDIR[v]) {
                dfs(u, y == 0 ? 1 : cnt + 1, wht);
                y++;
            }
        }
    };
    dfs(1,1,0);
    dfs(1,1,1);
    int t = 1;
    int y = 1;
    while (adjDIR[t][1]) {
        y++;
        t = adjDIR[t][1];
    }
    int w = 1;
    int g = 1;
    while (adjESQ[w][1]) {
        g++;
        w = adjESQ[w][1];
    }
    cout << n + m - max(min(ans1,y),min(ans2, g)) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





