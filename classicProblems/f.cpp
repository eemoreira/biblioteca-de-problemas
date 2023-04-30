#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e4 + 5;
ll a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<ll> dp(2 * n), g(2 * n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int l = j; 
                int r = j+i-1; 
                if ((i & 1) == (n & 1)) dp[l] = max(g[l] + a[r], a[l] + g[l + 1]);
                else dp[l] = min(g[l], g[l + 1]);
            }
            g = dp;
        }
        cout << g[1] << '\n';
    }
}




