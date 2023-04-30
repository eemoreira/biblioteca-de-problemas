#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    double n;
    cin >> n;
    n *= 10;
    n *= 6;
    n = 500 - n;
    dbg(n/4);
    n /= 4;
    int t = n;
    cout << t/10 << '.' << t%10 << '\n';
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





