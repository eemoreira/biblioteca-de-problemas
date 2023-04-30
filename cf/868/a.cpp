#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */


void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        int y = n - i;
        if (i * (i - 1) / 2 + y * (y - 1) / 2 == k) {
            cout << "yes\n";
            for (int j = 0; j < i; j++) cout << 1 << ' ';
            for (int j = 0; j < y; j++) cout << -1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "no\n";
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





