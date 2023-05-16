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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<ll>> p(26, vector<ll>(n));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = (j == 0 ? 0 : p[i][j - 1]) + (s[j] - 'a' == i);
        }
    }
    while (q--) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        --l; --r;
        int i = c - 'a';
        ll ans = 0;
        int len = r - l;
        if (l >= n) {
            l = l % n;
        }
        r = l + len;
        if (r >= n) {
            ans = p[i][r % n];
            ans += p[i][n - 1] * ((r - n) / n);
            r = n - 1;
        }
        ans += p[i][r] - (l == 0 ? 0 : p[i][l - 1]);
        cout << ans << '\n';
    }
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





