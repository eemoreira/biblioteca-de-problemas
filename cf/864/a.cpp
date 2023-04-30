#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    ll n, m, a, b, x, y;
    cin >> n >> m >> a >> b >> x >> y;
    if (a == n) a = 1;
    if (b == m) b = 1;
    if (x == n) x = 1;
    if (y == m) y = 1;
    int ans = 4;
    ans = min(ans, 4 - (a == 1) - (b == 1));
    ans = min(ans, 4 - (x == 1) - (y == 1));
    cout << ans << '\n';
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





