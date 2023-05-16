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
ll F[25];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(26);
    for (auto u : s) f[u - 'a']++;
    if (n & 1) {
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            bool ok = true;
            ll now = F[n >> 1];
            if (f[i] & 1) {
                f[i]--;
                for (auto u : f) {
                    ok &= !(u & 1);
                    now /= F[u >> 1];
                }
                f[i]++;
                if (ok) ans += now;
            }
        }
        cout << ans << '\n';
    }
    else {
        ll ans = F[n >> 1];
        for (auto &u : f) {
            if (u & 1) {
                cout << 0 << '\n';
                return;
            }
            ans /= F[u >> 1];
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    F[0] = 1;
    for (int i = 1; i < 21; i++) F[i] = F[i - 1] * i;
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





