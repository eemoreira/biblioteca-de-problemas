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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    a[0] = 1e18;
    a[n] = 1e18;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        ll k, x;
        cin >> k >> x;
        dbg(k, x);
        a[k] = x;
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





