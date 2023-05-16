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

int n, x;

inline void calc(vector<int>& a, vector<int>& f) {
    int s = a.size();
    for (int i = 0; i < 1 << s; i++) {
        int now = 0;
        bool ok = true;
        for (int j = 0; j < s; j++) {
            if (i >> j & 1) {
                if (now + a[j] > x) {
                    ok = false;
                    break;
                }
                now += a[j];
            }
        }
        if (ok) f.emplace_back(now);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<int> a((n + 1) / 2), b(n / 2);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;
    vector<int> mapa, mapb;
    calc(a, mapa);
    calc(b, mapb);
    sort(mapa.begin(), mapa.end());
    sort(mapb.begin(), mapb.end());
    ll ans = 0;
    int ta = mapa.size();
    int tb = mapb.size();
    dbg(mapa);
    dbg(mapb);
    for (int i = 0, j = tb - 1; i < ta && j >= 0;) {
        ll v = 0;
        int t = i;
        while (t < ta && mapa[i] == mapa[t]) {
            t++;
            v++;
        }
        while (j >= 0 && mapb[j] + mapa[i] > x) j--;
        if (j >= 0 && mapb[j] + mapa[i] == x) {
            ll w = 0;
            int y = j;
            while (y >= 0 && mapb[j] == mapb[y]) {
                w++;
                y--;
            }
            ans += v * w;
            j = y;
        }
        i = t;
    }
    cout << ans << '\n';
}





