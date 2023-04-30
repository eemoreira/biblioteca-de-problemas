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

// 110011
// 111001
// 111100
// 011110
// 001111
// 100111

/* stop freaking out pls */
void solve() {
    string s;
    cin >> s;
    s += s;
    int n = s.size();
    if (s == string(n, '1')) {
        n >>= 1;
        cout << 1LL * n * n << '\n';
        return;
    }
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        while (cnt < n/2 && i < n && s[i] == '1') {
            cnt++;
            i++;
        }
        mx = max(mx, cnt);
    }
    ll ans = 0;
    for (int i = 0; i < mx; i++) {
        ans = max(ans, (mx - i) * (i + 1));
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





