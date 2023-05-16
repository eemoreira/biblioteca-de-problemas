#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = n;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            ok &= a[i] * j <= a[j] * i;
        }
        if (ok) m = i;
    }
    vector<ll> dp(n * (m + 1) + 1, 1e18);
    for (int i = 1; i <= n; i++) dp[i] = a[i];
    for (int i = n + 1; i <= n * (m + 1); i++) {
        for (int j = i - n; j <= i; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    dbg(dp);
    while (q--) {
        int x;
        cin >> x;
        if (x <= n) {
            cout << dp[x] << '\n';
        }
        else {
            int j = max(0, (x - (m + 1) * n + m - 1) / m);
            dbg(j);
            cout << j * dp[m] + dp[x - j * m] << '\n';
        }
    }
}





