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
    long double a,b,c,d;
    cin >> a >> b >> c >> d;
    long double ans = 0;
    long double x = a / b;
    a = 1 - a / b;
    c = 1 - c / d;
    while (x > 1e-10) {
        ans += x;
        x *= a;
        x *= c;
    }
    cout << setprecision(15) << fixed;
    cout << ans << '\n';
}





