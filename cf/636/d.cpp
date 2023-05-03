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
    vector<int> f(2 * k + 5);
    vector<int> freq(2 * k + 5);
    for (int i = 0; i < n >> 1; i++) {
        f[min(a[i], a[n - i - 1]) + 1]++;
        f[max(a[i], a[n - i - 1]) + k + 1]--;
        freq[a[i] + a[n - i - 1]]++;
    }
    for (int i = 1; i < 2 * k + 5; i++) f[i] += f[i-1];
    dbg(f);
    for (int i = 2; i <= 2 * k; i++) {
        ans = min(ans, f[i] + 2 * (n/2 - f[i]) - freq[i]);
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





