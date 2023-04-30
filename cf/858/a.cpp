#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (b > d) cout << -1 << '\n';
    else {
        int ans = 0;
        ans += d - b;
        a += d - b;
        if (c > a) cout << -1 << '\n';
        else {
            ans += a - c;
            cout << ans << '\n';
        }
    }
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





