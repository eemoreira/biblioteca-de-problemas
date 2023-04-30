#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
// 5 * x = n -> x = n / 5
// 10 * y = n -> y = n / 10
// 2 * z = n -> z = n / 2
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long g = 0;
        long long l = 1;
        int ptr = i;
        while (ptr < n) {
            g = __gcd(g, a[ptr] * b[ptr]);
            l = lcm(l, b[ptr]);
            dbg(g,l);
            if (g % l == 0) {
                ptr++;
            }
            else {
                ptr--;
                break;
            }
        }
        i = ptr;
        ans++;
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





