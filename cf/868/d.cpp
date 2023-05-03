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
// abcabc -> 3
// abcbca -> 5
// abccba -> 6
// abcabcc -> 4


void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(2, vector<int>(k));
    for (auto &u : a[0]) cin >> u;
    for (auto &u : a[1]) cin >> u;
    string ans = "abc";
    const string abc = "abc";
    bool ok = true;
    int x = 3;
    int y = 0;
    for (int i = 0; i < k; i++) {
        if (a[1][i] > a[0][i] || a[1][i] < x) {
            ok = false;
        }
        while ((int)ans.size() < a[0][i]) {
            if (x < a[1][i]) {
                ans += char('a' + i + 3);
                x++;
            }
            else {
                ans += abc[y % 3];
                y++;
            }
        }
        if (x != a[1][i]) ok = false;
    }
    if (ok) cout << "yes\n" << ans << '\n';
    else cout << "no\n";
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





