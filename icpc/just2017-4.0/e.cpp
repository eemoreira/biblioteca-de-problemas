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

void calc(int x, int y, ll val, vector<vector<int>>& a, map<int,int>& f) {
    val = val * a[x][y] % mod;
    if (x + 1 == (int)a.size()) {
        f[val]++;
        return;
    }
    for (int i = 0; i < 6; i++) {
        calc(x + 1, i, val, a, f);
    }
}

ll Inv(ll b) {
    ll ans = 1;
    int e = mod - 2;
    while (e) {
        if (e & 1) ans = ans * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return ans;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<vector<int>> a((n + 1) / 2, vector<int>(6)), b(n >> 1, vector<int>(6));
    map<int,int> mapa, mapb;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n >> 1; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < 6; i++) {
        calc(0, i, 1ll, a, mapa);
        calc(0, i, 1ll, b, mapb);
    }
    ll ans = 0;
    dbg(mapa);
    dbg(mapb);
    for (auto [u, v] : mapa) {
        ll y = x * Inv(u) % mod;
        ans += (ll)v * mapb[y];
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





