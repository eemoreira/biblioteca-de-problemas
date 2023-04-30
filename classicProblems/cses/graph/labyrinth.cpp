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
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && a[x][y] != '#';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    pair<int,int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                s = {i, j};
            }
        }
    }
    vector<vector<char>> dir(n, vector<char>(m));
    vector<vector<pair<int,int>>> last(n, vector<pair<int,int>>(m));
    map<pair<int,int>, char> f;
    f[make_pair(0, 1)] = 'R';
    f[make_pair(0, -1)] = 'L';
    f[make_pair(1, 0)] = 'D';
    f[make_pair(-1, 0)] = 'U';

    pair<int,int> end = {-1,-1};
    queue<pair<int,int>> q;
    q.emplace(s);

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (a[i][j] == 'B') {
            end = {i, j};
            break;
        }
        for (auto [x, y] : mv) {
            if (valid(i + x, j + y)) {
                dir[i + x][j + y] = f[make_pair(x, y)];
                last[i + x][j + y] = make_pair(i, j);
                q.emplace(i + x, j + y);
            }
        }
    }
    if (end != make_pair(-1, -1)) {
        cout << "YES\n";
        string ans = "";
        while (end != s) {
            ans += dir[end.first][end.second];
            end = last[end.first][end.second];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
    else {
        cout << "NO\n";
    }
}





