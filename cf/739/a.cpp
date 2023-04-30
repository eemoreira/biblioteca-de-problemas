#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
vector<int> f;
void solve() {
    int n;
    cin >> n;
    cout << f[n-1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i < 5000; i++) {
        if (i % 3 && i%10 != 3) {
            f.emplace_back(i);
        }
    }
    while (tt--) {
        solve();
    }
}





