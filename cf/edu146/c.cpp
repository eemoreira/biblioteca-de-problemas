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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    vector<int> ans1, ans2;
    int x = s1;
    int y = s2;
    for (int i = 0; i < n; i++) {
        if (s1 <= s2) {
            ans1.emplace_back(a[i].second);
            s1 += x;
        }
        else {
            ans2.emplace_back(a[i].second);
            s2 += y;
        }
    }
    cout << ans1.size() << ' ';
    for (auto u : ans1) cout << u+1 << ' ';
    cout << '\n';
    cout << ans2.size() << ' ';
    for (auto u : ans2) cout << u+1 << ' ';
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





