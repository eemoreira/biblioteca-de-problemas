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
    int lg = 0;
    long long t = n;
    vector<int> num;
    while (t) {
        num.emplace_back(t % 10);
        t /= 10;
        lg++;
    }
    reverse(num.begin(), num.end());
    int ans = lg + 1;
    for (int i = 0; i < 62; i++) {
        t = 1LL << i;
        vector<int> g;
        while (t) {
            g.emplace_back(t % 10);
            t /= 10;
        }
        reverse(g.begin(), g.end());
        int ptrnum = 0, ptrg = 0;
        int now = 0;
        while (ptrnum < (int)num.size() || ptrg < (int)g.size()) {
            if (ptrnum == (int)num.size()) {
                now += (int)g.size() - ptrg;
                break;
            }
            if (ptrg == (int)g.size()) {
                now += (int)num.size() - ptrnum;
                break;
            }
            if (num[ptrnum] == g[ptrg]) {
                ptrnum++;
                ptrg++;
            }
            else {
                ptrnum++;
                now++;
            }
        }
        ans = min(ans, now);
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





