#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> p(60);
    p[0] = 1;
    for (int i = 1; i < 60; i++) {
        p[i] = 2 * p[i-1];
    }
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long ones = 0;
        long long zs = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            ones += a[i][j];
            zs += !a[i][j];
        }
        ans += 1LL << ones;
        ans += 1LL << zs;
        ans -= 2;
    }
    for (int i = 0; i < m; i++) {
        long long ones = 0;
        long long zs = 0;
        for (int j = 0; j < n; j++) {
            ones += a[j][i];
            zs += !a[j][i];
        }
        ans += 1LL << ones;
        ans += 1LL << zs;
        ans -= ones;
        ans -= zs;
        ans -= 2;
    }
    cout << ans << '\n';
}





