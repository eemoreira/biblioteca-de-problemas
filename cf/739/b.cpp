#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    if (a > b) swap(a,b);
    int n = (b-a) * 2;
    if (b > n) cout << -1 << '\n';
    else if (c > n) cout << -1 << '\n';
    else cout << (c <= n/2 ? c + n/2 : c - n/2) << '\n';
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





