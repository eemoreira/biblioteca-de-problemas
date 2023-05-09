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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> f(105);
    for (auto u : a) f[u]++;
    int ans = -1;
    int cnt = 0;
    for (int i = 0; i <= 100; i++) {
        cnt += f[i];
        if (i == n - cnt) ans = i;
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





