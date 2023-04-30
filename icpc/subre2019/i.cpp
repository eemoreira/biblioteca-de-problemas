#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int maxn = 401;
ll q[2][maxn][maxn][maxn];
ii temp[2][maxn];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    memset(q, 0x3f, sizeof(q));
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        temp[0][i] = temp[1][i] = {x, i};
    }
    sort(temp[0], temp[0] + n);
    sort(temp[1], temp[1] + n);
    reverse(temp[1], temp[1] + n);
    for (int i = 0; i < m; i++) {
        ll v, u, w;
        scanf("%lld%lld%lld", &v, &u, &w);
        --v; --u;
        for (int j = 0; j < 2; j++) {
            q[j][0][v][u] = q[j][0][u][v] = w;
        }
    }
    for (int t = 0; t < 2; t++) {
        for (int z = 1; z <= n; z++) { 
            int k = temp[t][z - 1].second;
            for (int x = 0; x < n; x++) {
                int i = temp[t][x].second;
                for (int y = 0; y < n; y++) {
                    int j = temp[t][y].second;
                    q[t][z][i][j] = min(q[t][z - 1][i][j], q[t][z - 1][i][k] + q[t][z - 1][k][j]);
                }
            }
        }
    }
    vector<vector<int>> find(2, vector<int>(n + 1));
    for (int j = 0; j < 2; j++) {
        ll now = temp[j][0].first;
        int y = 1;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || now != temp[j][i].first) {
                if (now == temp[j][i].first) i++;
                else find[j][y + 1] = i + 1;
                find[j][y] = i;
                now = temp[j][i].first;
                ++y;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        find[0][i] = max(find[0][i - 1], find[0][i]);
        find[1][i] = max(find[1][i], find[1][i - 1]);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int v, u, k, t;
        scanf("%d%d%d%d", &v, &u, &k, &t);
        --v; --u;
        k = find[t][k];
        printf("%lld\n", q[t][k][v][u] >= 1e15? -1 : q[t][k][v][u]);
    }
}









