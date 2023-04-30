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
    int x = 0;
    string s;
    cin >> s;
    vector<vector<int>> f(2, vector<int>(26));
    for (int i = 0; i < n; i+=2) {
        f[0][s[i]-'a'] = 1;
    }
    for (int i = 1; i < n; i+=2) {
        f[1][s[i]-'a'] = 1;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= f[0][s[i]-'a'] != f[1][s[i]-'a'];
    }
    cout << (ok ? "yes\n" : "no\n");
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





