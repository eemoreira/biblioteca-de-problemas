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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> d;
    for (int i = 0; i < n >> 1; i++) {
        d.emplace_back(abs(a[i] - a[n -1 -i]));
    }
    int ans = 0;
    for (auto u : d) ans = gcd(ans, u);
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
