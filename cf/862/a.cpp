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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int x = 0;
    for (auto u : a) x ^= u;
    if (!x) {
        cout << 0 << '\n';
    }
    else {
        cout << (n & 1 ? x : -1) << '\n';
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





