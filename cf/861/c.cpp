#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    ll l, r;
    cin >> l >> r;
    string L = to_string(l);
    string R = to_string(r);
    string ans = L;
    string y = L;
    if ((int)R.size() > (int)L.size()) {
        cout << string((int)L.size(), '9') << '\n';
        return;
    }
    sort(begin(y), end(y));
    int MN = y.back() - y.front();
    int p = 0;
    while (p < (int)L.size() && L[p] == R[p]) p++;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool found = false;
            char mn = min(i, j) + '0';
            char mx = max(i, j) + '0';
            int ptr = p;
            int h = -1;
            string last;
            string now;
            for (int d = 0; d < p; d++) now += L[d];
            bool ok = true;
            while (ptr < (int)L.size()) {
                if (found) {
                    now += mn;
                }
                else if (mn > L[ptr]) {
                    found = true;
                    now += mn;
                }
                else if (mn == L[ptr]) {
                    if (mx > L[ptr]) {
                        last = now;
                        last += mx;
                        h = ptr;
                    }
                    now += mn;
                }
                else if (mx > L[ptr]) {
                    found = true;
                    now += mx;
                }
                else if (mx == L[ptr]) {
                    now += mx;
                }
                else if (h != -1) {
                    now = last;
                    ptr = h;
                    found = true;
                }
                else ok = false;
                ptr++;
            }
            if (ok && now >= L && now <= R) {
                string g = now;
                sort(begin(now), end(now));
                int t = now.back() - now.front();
                dbg(g, t);
                if (t < MN) {
                    MN = t;
                    ans = g;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}





