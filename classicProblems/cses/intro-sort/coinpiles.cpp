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

// 2 * x + y = a
// 2 * y + x = b
// x - y = a - b

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        int dif = a - b;
        ll l = dif, r = 1e9;
        bool ok = false;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll now = 2 * mid + mid - dif;
            if (now <= a) {
                l = mid + 1;
                if (now == a) ok = true;
            }
            else {
                r = mid - 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}





