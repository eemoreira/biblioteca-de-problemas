#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;
    int ans = -1;
    int more = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + more <= t && b[i] > mx) {
            mx = b[i];
            ans = i + 1;
        }
        more++;
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





