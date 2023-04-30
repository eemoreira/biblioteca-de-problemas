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
    ll l, r;
    cin >> l >> r;
    ll ans = l;
    ll mn = 10;
    for (ll i = l; i <= r; i++) {
        string now = to_string(i);
        sort(begin(now), end(now));
        int t = now.back() - now.front();
        if (t < mn) {
            ans = i;
            mn = t;
        }
    }
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





