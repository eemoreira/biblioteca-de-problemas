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
const int mod = 1e9 + 7;
const int maxn = 5e3 + 5;
ll f[maxn], invf[maxn];

ll nCr(int n, int r) {
    return f[n] * invf[n - r] % mod * invf[r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> dp_max(n), dp_ans(n), a(n);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        pos[a[i]].emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
        int r = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin();
        int l = r - (k - 1);
        if (l >= 0) {
            int L = pos[a[i]][l];
            dp_max[i] = 1;
            for (int j = 0; j < L; j++) {
                dp_max[i] = max(dp_max[i], dp_max[j] + 1);
            }
            if (dp_max[i] == 1) dp_ans[i] = nCr(r, k - 1);
            else for (int j = 0; j < L; j++) {
                if (dp_max[j] == dp_max[i] - 1) {
                    int up = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), j) - pos[a[i]].begin();
                    dp_ans[i] = (dp_ans[i] + nCr(r - up, k - 1) * dp_ans[j] % mod) % mod;
                }
            }
        }
    }
    dbg(dp_max);
    int mx = *max_element(dp_max.begin(), dp_max.end());
    if (mx == 0) cout << 1 << '\n';
    else {
        ll ans = 0;
        for (int i = 0; i < n; i++) if (dp_max[i] == mx) {
            ans = (ans + dp_ans[i]) % mod;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        invf[i] = 1;
        int e = mod - 2;
        ll b = f[i];
        while (e) {
            if (e & 1) invf[i] = invf[i] * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





