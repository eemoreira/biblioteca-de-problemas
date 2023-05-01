#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int ans = n;
    vector<int> pmax(n >> 1);
    vector<int> f(2 * k + 5);
    for (int i = 0; i < n >> 1; i++) {
        pmax[i] = max(a[i], a[n - i - 1]) + k;
        f[min(a[i], a[n - i - 1]) + 1]++;
    }
    for (int i = 1; i < 2 * k + 5; i++) f[i] += f[i-1];
    dbg(f);
    n >>= 1;
    for (int i = 0; i < n >> 1; i++) {
        ans = min(ans, f[pmax[i]] + 2 * (n - f[pmax[i]]));
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





