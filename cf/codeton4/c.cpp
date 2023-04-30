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
    ll n, c, d;
    cin >> n >> c >> d;
    map<int,int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    ll ans = 0;
    vector<int> a;
    for (auto [u,v] : f) {
        ans += c * (v - 1);
        a.emplace_back(u);
    }
    sort(a.begin(), a.end());
    n = a.size();
    ll ps = c * (n - 1) + (c + d) * (a[0] != 1);
    dbg(a);
    for (int i = 0; i < n ; i++) {
        ll now = d * (a[i] - i - 1) + c * (n - i -1);
        dbg(now);
        ps = min(ps, now);
    }
    ans += ps;
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





