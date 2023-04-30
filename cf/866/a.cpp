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
    int ans = s[0] == '_';
    if (n > 1) ans += s.back() == '_';
    else {
        cout << (s[0] == '_' ? 2 : 1) << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (i < n && s[i] == '_') {
            cnt++;
            i++;
        }
        if (cnt > 1) ans += cnt - 1;
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





