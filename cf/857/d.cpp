#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    map<int,int> cp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
            if (j == 0) {
                cp[a[i][j]];
            }
        }
    }
    sort(a.begin(), a.end());
    int k = 0;
    for (auto &u : cp) {
        u.second = ++k;
    }
    set<int> l, wtf;
    map<int,int> best;
    for (int i = 0; i < n; i++) {
        wtf.emplace(a[i][0]);
        best[a[i][0]] = max(best[a[i][0]], a[i][1]);
    }
    vector<int> t;
    for (auto u : wtf) {
        t.emplace_back(best[u]);
    }
    vector<int> suf(k + 1);
    suf[k] = t.back();
    for (int i = k-1; i > 0; i--) {
        suf[i] = max(suf[i+1], t[i-1]);
    }
    vector<int> vis(k+1);
    int ans = 1e9 + 50;
    dbg(a);
    dbg(suf);
    dbg(k);
    for (int i = 0; i < n; i++) {
        int now = cp[a[i][0]] == k ? 0 : suf[cp[a[i][0]]+1];
        if (vis[cp[a[i][0]]]) {
            l.emplace(a[i][1]);
        }
        vis[cp[a[i][0]]] = 1;
        auto lb = l.lower_bound(a[i][0]);
        if (i > 0 && lb == l.end()) --lb;
        while (lb != l.begin() && *lb > a[i][0]) --lb;
        if (i > 0 && *lb >= now) {
            int x = *lb;
            dbg(*lb);
            ans = min(ans, abs(a[i][0] - x));
        }
        auto up = l.upper_bound(a[i][0]);
        if (i > 0 && up == l.end()) --up;
        if (i > 0 && *up >= now) {
            int x = *up;
            dbg(*up);
            ans = min(ans, abs(a[i][0] - x));
        }
        if (cp[a[i][0]] < k) {
            ans = min(ans, abs(now - a[i][0]));
        }
        dbg(l);
        dbg(a[i][0], now, *up, *lb);
        dbg(abs(a[i][0] - *up), abs(a[i][0] - *lb));
        dbg(abs(a[i][0] - now));
        dbg(ans);
        l.emplace(a[i][1]);
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





