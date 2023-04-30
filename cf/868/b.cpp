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
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
        --u;
    }
    vector<map<int,int>> b(k);
    vector<int> vis(n);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j+=k) {
            vis[j]++;
            b[i][a[j]]++;
        }
    }
    int ans = 0;
    bool found = false;
    for (int i = 0; i < k; i++) {
        for (auto &[u, v] : b[i]) {
            if (!v) continue;
            if (u % k != i) {
                bool ok = false;
                for (auto &[x, l] : b[u % k]) {
                    if (x % k == i) {
                        if (!l) continue;
                        if (found) {
                            cout << -1 << '\n';
                            return;
                        }
                        ok = true;
                        b[i][x]++;
                        b[i][u] = 0;
                        b[u % k][u]++;
                        b[u % k][x] = 0;
                        ans++;
                        break;
                    }
                }
                if (!ok) {
                    cout << -1 << '\n';
                    return;
                }
                found = true;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        ok &= a[i] == i + 1;
    }
    if (!ok) cout << -1 << '\n';
    cout << ans << '\n';
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
