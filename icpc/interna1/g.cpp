#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, vector<int>> i3;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

i3 comp(i3 x, i3 y) {
    if (x.first == y.first) {
        return x.second < y.second ? x : y;
    }
    return x.first > y.first ? x : y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    vector<int> neutral(4, 1e9);
    i3 ans = i3(-1e18,neutral);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                for (int d = 1; d <= m; d++) {
                    if (i > k || j > d) continue;
                    ll now = p[k][d] - p[k][j - 1] - p[i - 1][d] + p[i - 1][j - 1];
                    vector<int> x = {i, j, k, d};
                    ans = comp(ans, i3(now, x));
                }
            }
        }
    }
    cout << ans.first << '\n';
    cout << ans.second[0] << ' ' << ans.second[1] << '\n';
    cout << ans.second[2] << ' ' << ans.second[3] << '\n';
}





