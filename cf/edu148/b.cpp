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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), p(n + 1), suf(n + 2);
    ll ans = 0;
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i - 1];
    }
    for (int i = 0; i/2 <= k; i += 2) {
        ans = max(ans, p[n] - p[i] - suf[n - (k - i / 2) + 1]);
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





