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
    long long n;
    cin >> n;
    vector<vector<long long>> a(5, vector<long long>(5));
    a[0] = {16,9,4,1,0};
    for (int i = 1; i < 5; i++) {
        a[i][i-1] = 1;
    }
    dbg(a);
    const int mod = 1e9 + 7;
    vector<vector<long long>> basecase = {{1},{0},{0},{0},{0}};
    auto mul = [&](vector<vector<long long>> x, vector<vector<long long>> y) {
        vector<vector<long long>> ans((int)x.size(), vector<long long>((int)y[0].size()));
        for (int i = 0; i < (int)x.size(); i++) {
            for (int j = 0; j < (int)y[0].size(); j++) {
                for (int k = 0; k < (int)x[0].size(); k++) {
                    ans[i][j] += (x[i][k] * y[k][j]) % mod;
                    ans[i][j] %= mod;
                }
            }
        }
        return ans;
    };
    auto bpw = [&](vector<vector<long long>> x, long long e) {
        vector<vector<long long>> ans = {{1,0,0,0,0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}};
        while (e) {
            if (e & 1) {
                ans = mul(x, ans);
            }
            e >>= 1;
            x = mul(x,x);
        }
        return ans;
    };
    long long ans = 0;
    vector<vector<long long>> lol = bpw(a, n / 10);
    vector<vector<long long>> g = mul(lol, basecase);
    dbg(lol);
    dbg(g);
    for (int i = 0; i < 5; i++) {
        if (i == 4 && n >= 45 && (n%10 >= 5)) {
            continue;
        }
        ans += g[i][0] % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}





