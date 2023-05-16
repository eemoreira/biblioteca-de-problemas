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
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> ans(n);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[i] > b[j]) j++;
        ans[i] = max(0ll, (ll) j - i);
    }
    ll res = 1;
    for (int i = 0; i < n; i++) res = res * ans[i] % mod;
    cout << res << '\n';
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





