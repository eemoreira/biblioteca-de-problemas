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
    if (s[0] == '0') {
        cout << 0 << '\n';
    }
    else {
        int ans = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '?') {
                if (i == 0) ans *= 9;
                else ans *= 10;
            }
        }
        cout << ans << '\n';
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





