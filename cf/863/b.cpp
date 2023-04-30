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
    int n,x,y,l,r;
    cin >> n >> x >> y >> l >> r;
    x = (x > n/2 ? n - x + 1 : x);
    y = (y > n/2 ? n - y + 1: y);
    l = (l > n/2 ? n - l + 1: l);
    r = (r > n/2 ? n - r + 1: r);
    dbg(x, y, l, r);
    cout << abs(min(x, y) - min(l, r)) << '\n';
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





