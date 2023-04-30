#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

const int maxn = 1005;
string a[maxn];
bool vis[maxn][maxn];
int n, m;
vector<pair<int,int>> mv = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && a[x][y] == '.';
}

void dfs(int i, int j) {
    vis[i][j] = true;
    for (auto u : mv) {
        int x = u.first;
        int y = u.second;
        if (valid(i + x, j + y)) {
            dfs(i + x, j + y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i, j)) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}





