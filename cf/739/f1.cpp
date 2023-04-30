#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> bomba;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bomba.emplace_back(i,j);
        }
    }
    vector<int> num;
    int t = n;
    int p = 1;
    while (t) {
        num.emplace_back(t % 10);
        t /= 10;
        p *= 10;
    }
    reverse(num.begin(), num.end());
    p /= 10;
    dbg(p);
    long long ans = 1e11;
    for (auto [u,v] : bomba) {
        if (k == 1 && u != v) continue;
        int mx = max(u, v);
        int mn = min(u, v);
        int b = p;
        long long now = 0;
        long long last = 0;
        int keep = 0;
        int ptr = 0;
        bool ok = false;
        bool c = true;
        for (int i = 0; i < (int)num.size(); i++, b /= 10) {
            if (ok) {
                now += mn * b;
            }
            else if (mn > num[i]) {
                ok = true;
                now += mn * b;
            }
            else if (mn == num[i]) {
                if (mx > num[i]) {
                    last = now + mx * b;
                    ptr = i;
                    keep = b;
                }
                now += mn * b;
            }
            else if (mx > num[i]) {
                ok = true;
                now += mx * b;
            }
            else if (mx == num[i]) {
                now += mx * b;
            }
            else {
                if (last) {
                    if (mn == 3 && mx == 6) {
                        dbg(ptr, i, last, mn, mx, b);
                    }
                    now = last;
                    i = ptr;
                    b = keep;
                    ok = true;
                }
                else {
                    c = false;
                }
            }
        }
        if (!c) continue;
        if (now >= n) {
            ans = min(ans, now);
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}






