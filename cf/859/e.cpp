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
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid - l + 1 << ' ';
        for (int i = l; i <= mid; i++) {
            cout << i << ' ';
        }
        cout << endl;
        cout.flush();
        long long now;
        cin >> now;
        if (now > (p[mid] - p[l-1])) {
            r = mid-1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
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





