#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

// dif + (1 + dif - 1) + (1 + dif - 2) + (1 + dif - 3) + .. + (1 + dif - x)
// dif * x + x - x * (x + 1) / 2

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    int l = pos[0], r = pos[0];
    ll ans = 1;
    for (int i = 0; i < n - 1; i++) {
        int mex = i + 1;
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        int size = r - l + 1;
        int max_len = min(n, 2 * (i + 1));
        if (size > max_len) continue;
        int dif = max_len - size;
        if (pos[mex] < l) {
            for (int j = pos[mex] + 1; j <= l; j++) {
                int size = r - j + 1;
                int x = max(0, min(n - j, max_len) - size + 1);
                ans += x;
            }
        }
        else if (pos[mex] > r) {
            for (int j = pos[mex] - 1; j >= r; j--) {
                int size = j - l + 1;
                int x = max(0, min(j + 1, max_len) - size + 1);
                ans += x;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}





