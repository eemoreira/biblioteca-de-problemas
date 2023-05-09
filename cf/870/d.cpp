#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,ll> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n), suf(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    p[0] = a[0];
    suf[n - 1] = a[n - 1] - (n - 1);
    for (int i = 1; i < n; i++) {
        p[i] = max(p[i - 1], a[i] + i);
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i] - i);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, p[i - 1] + suf[i + 1] + a[i]);
    }
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





