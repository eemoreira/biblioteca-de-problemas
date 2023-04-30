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

// n = max(0,(h - a + a - b - 1)) / (a - b) + 1
// 7 3 6
// 7 -> 4
// 11 -> 8
// 15 -> 12
// 19 -> 16
// 23 -> 20
// 27 

void solve() {
    int q;
    cin >> q;
    ll minH = 0;
    ll maxH = 1e18;
    auto ans = [&](ll a, ll b, ll h) {
        if (a >= h) return 1ll;
        return max(0ll, h - b - 1) / (a - b) + 1;
    };
    vector<ll> print;
    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            ll a, b, n;
            cin >> a >> b >> n;
            /* test(a, b, n); */
            ll nowminH = a + (n - 2) * (a - b) + 1;
            ll nowmaxH = a + (n - 1) * (a - b);
            if (n == 1) {
                nowmaxH = a;
                nowminH = 1;
            }
            if (!(nowminH > maxH || nowmaxH < minH)) {
                minH = max(minH, nowminH);
                maxH = min(maxH, nowmaxH);
                print.emplace_back(1);
            }
            else print.emplace_back(0);
        }
        else {
            ll a, b;
            cin >> a >> b;
            if (ans(a, b, minH) == ans(a, b, maxH)) print.emplace_back(ans(a, b, maxH));
            else print.emplace_back(-1);
        }
    }
    for (auto u : print) cout << u << ' ';
    cout << '\n';
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






