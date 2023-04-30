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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ll x, y;
        cin >> x >> y;
        ll now;
        if (x >= y) {
            if (x % 2 == 0) {
                now = x * x;
                now -= y - 1;
            }
            else {
                now = x * x - 2ll * (x - 1);
                now += y - 1;
            }
        }
        else {
            if (y % 2 == 0) {
                now = y * y - 2ll * (y - 1);
                now += x - 1;
            }
            else {
                now = y * y;
                now -= x - 1;
            }
        }
        cout << now << '\n';
    }
}





