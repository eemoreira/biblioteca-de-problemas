#blob:https://web.whatsapp.com/534e2736-2f95-4649-9e1c-873b7b8f4d6c include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

vector<vector<int>> a, d;
vector<ii> mv = {{1,0},{0,1},{-1,0},{0,-1}};
int c[105];
int n, m, Q;

void multibfs(int ptr) {
    if (ptr > Q) return;
    queue<ii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != c[ptr]) {
                d[i][j] = 1e9;
            }
            else {
                q.emplace(i, j);
            }
        }
    }
    auto valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    if (!ptr) {
        q.emplace(0,0);
        d[0][0] = 0;
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [i, j] : mv) {
            int xi = x + i;
            int yj = y + j;
            if (valid(xi, yj) && d[x][y] + 1 < d[xi][yj]) {
                d[xi][yj] = d[x][y] + 1;
                q.emplace(xi, yj);
            }
        }
    }
    multibfs(ptr + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a = d = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) cin >> c[i];
    multibfs(0);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == c[Q]) {
                ans = min(ans, d[i][j]);
            }
        }
    }
    cout << ans << '\n';
}





