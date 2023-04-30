#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    string t;
    cin >> t;
    int n = t.size();
    vector<int> last(26, 1e9);
    for (int i = 0; i < n; i++) {
        last[t[i] - 'a'] = i;
    }
    vector<int> have(26);
    string ord = "";
    for (int i = n - 1; i >= 0; i--) {
        if (!have[t[i]-'a']) {
            ord += t[i];
        }
        have[t[i]-'a']++;
    }
    int k = ord.size();
    int where = 0;
    for (auto u : ord) {
        if (have[u - 'a'] % k) {
            cout << -1 << '\n';
            return;
        }
        int y = have[u-'a'] / k;
        for (int i = 0; i < n; i++) {
            if (t[i] == u) {
                y--;
            }
            if (!y) {
                where = max(where, i);
                break;
            }
        }
        k--;
    }
    where++;
    string ans = t.substr(0, where);
    vector<int> vis(26);
    string check = ans;
    reverse(ord.begin(), ord.end());
    for (auto u : ord) {
        vis[u - 'a'] = 1;
        for (auto x : ans) {
            if (!vis[x - 'a']) {
                check += x;
            }
        }
    }
    if (check == t) {
        cout << ans << ' ' << ord << '\n';
    }
    else {
        cout << -1 << '\n';
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







