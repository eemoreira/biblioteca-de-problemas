#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<vector<ll>> mat;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int mod = 1e6;

mat mul(mat x, mat y) {
    mat ans((int)x.size(), vector<ll>((int)y[0].size()));
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = 0; j < (int)y[0].size(); j++) {
            for (int k = 0; k < (int)x[0].size(); k++) {
                x[i][k] %= mod;
                y[k][j] %= mod;
                ans[i][j]= (x[i][k] * y[k][j] % mod + ans[i][j]) % mod;
            }
        }
    }
    return ans;
}

mat bpw(mat a, ll e) {
    mat ans = {{1,0},{0,1}};
    while (e) {
        if (e & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, l;
    cin >> n >> k >> l;
    n /= 5;
    /* vector<ll> dp(n + 1); */
    /* dp[0] = 1; */
    /* dp[1] = k; */
    /* for (int i = 2; i <= n; i++) { */
    /*     dp[i] = k * dp[i-1] + l * dp[i-2]; */
    /* } */
    /* cout << dp[n] << '\n'; */
    mat r = {{k, l}, {1, 0}};
    mat x = {
        {1},
        {0}
    };
    mat ans = mul(bpw(r, n), x);
    string anss = to_string(ans[0][0]);
    int sz = anss.size();
    while (sz < 6) {
        cout << '0';
        sz++;
    }
    cout << anss << '\n';
}





