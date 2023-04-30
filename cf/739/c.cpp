#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
vector<long long> pf;
void solve() {
    int n;
    cin >> n;
    int id = lower_bound(pf.begin(), pf.end(), n) - pf.begin();
    if (pf[id] > n) id--;
    dbg(pf.back());
    int l = 0, r = 2 * id;
    int ans = 0;
    dbg(pf[id]);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (pf[id] + mid >= n) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    dbg(ans, id);
    int ret = min(ans+1, id);
    id -= (ans + 1 - ret);
    cout << ret << ' ' << id << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    pf.emplace_back(0);
    pf.emplace_back(1);
    int t = 2;
    for (long long i = 2;; i++) {
        long long now = i * i;
        if (now - t > 1e11) break;
        pf.emplace_back(now - t);
        t += 2;
    }
    while (tt--) {
        solve();
    }
}





