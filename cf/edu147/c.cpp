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
    string s;
    cin >> s;
    int n = s.size();
    if (s == string(n, s[0])) {
        cout << 0 << '\n';
        return;
    }
    int ans = __lg(n) + 1;
    for (int i = 0; i < 26; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] - 'a' == i) continue;
            int cnt = 0;
            while (j < n && s[j] - 'a' != i) {
                j++;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        ans = min(ans, __lg(mx) + 1);
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





