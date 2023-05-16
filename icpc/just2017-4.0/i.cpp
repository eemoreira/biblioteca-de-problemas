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
const int maxn = 2e5 + 5;
int a[maxn], dp[maxn], last[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = 0;
    }
    dp[1] = 0;
    last[a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (last[a[i]]) {
            dp[i] = min(dp[i], dp[last[a[i]]] + 1);
        }
        last[a[i]] = i;
    }
    cout << dp[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





