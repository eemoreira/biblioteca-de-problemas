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

int n, k;


void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<map<int,int>> b(k);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j+=k) {
            b[i][a[j]]++;
        }
    }
    int dif = 0;
    for (int i = 0; i < k; i++) {
        int y = i + 1;
        while (y <= n) {
            if (!b[i][y]) dif++;
            y += k;
        }
    }
    if (dif == 0) cout << 0 << '\n';
    else if (dif <= 2) cout << 1 << '\n';
    else cout << -1 << '\n';
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






