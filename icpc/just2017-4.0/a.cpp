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
    ll ans = 0;
    for (int i = 0; i < 31; i++) {
        ll now = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >> i & 1) {
                now++;
            }
            else {
                ans += (1 << i) * now * (now + 1) / 2;
                now = 0;
            }
        }
        ans += (1 << i) * now * (now + 1) / 2;
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





