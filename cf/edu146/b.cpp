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
    ll a, b;
    cin >> a >> b;
    ll ans = 1e18;
    for (ll i = 1; i <= max(a, b); i++) {
        ll t = i + (a + i - 1) / i + (b + i - 1) / i;
        dbg(t, ans);
        if (t <= ans + 10) {
            ans = min(ans, t);
        }
        else break;
    }
    cout << --ans << '\n';
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





