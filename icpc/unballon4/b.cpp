#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld a, c;
    cin >> a >> c;
    ld base = sqrt((a / 2) * (a / 2) + (c / 2) * (c / 2));
    ld r = a * c / (4 * base);
    ld circ = acos(-1) * r * r;
    ld los = a * c / 2;
    ld ret = a * c / 2;
    los -= circ;
    cout << setprecision(10) << fixed << ret << ' ' << los << ' ' << circ << '\n';
}





