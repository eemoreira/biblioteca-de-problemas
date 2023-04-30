#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n,q;
    cin >> n >> q;
    vector<long long> p(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i+1];
        p[i+1] += p[i];
    }
    long long sum = p[n];
    while (q--) {
        long long l,r,k;
        cin >> l >> r >> k;
        long long now = sum - (p[r] - p[l-1]);
        now += (l - r + 1) * k;
        cout << (now & 1 ? "yes\n" : "no\n");
    }
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





