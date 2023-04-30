#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    ll n;
    cin >> n;
    string ans = "";
    while (n) {
        int t = n % 9;
        if (t >= 4) t++;
        ans += t + '0';
        n /= 9;
    }
    reverse(ans.begin(), ans.end());
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





