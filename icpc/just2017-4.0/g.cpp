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
const int maxn = 1e6 + 5;
int a[maxn], p[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = max(a[i], p[i - 1]);
    }
    int ans = 0;
    int r = a[n];
    for (int i = n - 1; i > 1; i--) {
        if (r >= a[i] && p[i - 1] <= a[i]) {
            ans++;
        }
        dbg(r, p[i - 1]);
        r = min(r, a[i]);
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





