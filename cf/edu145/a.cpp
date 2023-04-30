#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s == string(n, s[0])) {
        cout << -1 << '\n';
    }
    else {
        set<int> t;
        for (auto u : s) t.emplace(u);
        if ((int)t.size() == 4) cout << 4 << '\n';
        else {
            vector<int> f(10);
            for (auto u : s) {
                f[u - '0']++;
            }
            cout << 2 * *max_element(f.begin(), f.end()) << '\n';
        }
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





