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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n * m);
    for (auto &u : a) cin >> u;
    sort(a.begin(), a.end());
    ll ans0 = max((n - 1) * m, n * (m - 1)) * (a.back() - a.front()) + min(m - 1, n - 1) * (a.back() - a[1]);
    ll ans1 = max((n - 1) * m , n * (m - 1)) * (a.back() - a.front()) + min(m - 1, n - 1) * (a[n*m - 2] - a.front());
    dbg(a.back(), a.front(), a[n*m - 2]);
    cout << max(ans0, ans1) << '\n';
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





