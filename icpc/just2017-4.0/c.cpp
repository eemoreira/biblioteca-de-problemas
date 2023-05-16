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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    auto lb = [&](int l, int r, int look) {
        ll ans = -1e18;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].first <= look) {
                ans = a[mid].first;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    };

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x = mod - 1 - a[i].first;
        dbg(x, a[i]);
        ll y = (a[i].first + max(lb(0, i - 1, x), lb(i + 1, n - 1, x))) % mod;
        ll z = (a[i].first + max(lb(0, i - 1, mod), lb(i + 1, n - 1, mod))) % mod;
        ans[a[i].second] = max(y, z);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
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





