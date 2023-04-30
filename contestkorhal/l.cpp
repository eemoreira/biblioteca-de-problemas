#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e5 + 5;

int ans[MAX];
bool vis[250][250];

vector<pair<int,int>> mv = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int a[250][250];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

int now = 0;
void dfs(int i, int j, int color) {
    vis[i][j] = true;
    now++;
    for (auto u : mv) {
        int x = u.first;
        int y = u.second;
        if (valid(i + x, j + y)) {
            if (a[i + x][j + y] == color) {
                dfs(i + x, j + y, color);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            ans[a[i][j]] = 1e9;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            now = 0;
            dfs(i,j,a[i][j]);
            ans[a[i][j]] = min(now, ans[a[i][j]]);
        }
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mn = min(mn, ans[a[i][j]]);
        }
    }
    cout << mn << '\n';
}





