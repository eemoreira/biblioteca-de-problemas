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
    map<int,int> last;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            last[x] = i;
        }
    }
    vector<pair<int,int>> p;
    for (auto u : last) {
        p.emplace_back(u.second, u.first);
    }
    sort(p.begin(), p.end());
    vector<int> ans(n);
    for (auto u : p) {
        if (ans[u.first]) continue;
        ans[u.first] = u.second;
    }
    for (auto u : ans) {
        if (!u) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto u : ans) {
        cout << u << ' ';
    }
    cout << '\n';
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





