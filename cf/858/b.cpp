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
    int zero = 0;
    int nonzero = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            ok &= x == 1;
        }
        zero += x == 0;
        nonzero += x != 0;
    }
    ok &= zero != n;
    if (nonzero < zero - 1 && ok) {
        cout << 2 << '\n';
    }
    else {
        cout << (nonzero >= zero - 1 ? 0 : 1) << '\n';
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





