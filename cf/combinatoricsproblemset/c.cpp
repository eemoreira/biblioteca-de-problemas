#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    const int mod = 998244353;
    int mx = 0;
    int ptr = 0;
    long long ans = 0;
    dbg(last);
    while (ptr < n) {
        if (!ans) ans = 1;
        else ans = ans * 2 % mod;
        for (int i = ptr; i <= mx; i++) {
            mx = max(mx, last[a[i]]);
        }
        ptr = mx + 1;
        mx = ptr;
    }
    cout << ans << '\n';
}





