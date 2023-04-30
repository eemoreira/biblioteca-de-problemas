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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;

    ii ans = {1,1};
    int sz = 1;
    for (int i = 1; i < n; i++) {
        ii now = {i, i};
        int cnt = 0;
        while (i < n && b[i] >= b[i-1]) {
            if (b[i-1] != a[i-1]) cnt++;
            if (b[i] != a[i]) cnt++;
            i++;
            now.second++;
        }
        if (cnt && now.second - now.first + 1 > sz) {
            ans = now;
            sz = now.second - now.first + 1;
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
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





