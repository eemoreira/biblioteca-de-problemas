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
    int n, m;
    cin >> n >> m;
    set<int> x;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        if (now == -1) l++;
        else if (now == -2) r++;
        else x.emplace(now);
    }
    int ans = max((int)x.size() + l, (int)x.size() + r);
    int y = 0;
    int z = x.size();
    for (auto u : x) {
        y++;
        z--;
        int L = min(u, l + y);
        int R = min(m - u, r + z);
        ans = max(ans, L + R);
    }
    cout << min(m, ans) << '\n';
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





