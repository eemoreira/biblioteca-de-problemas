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
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << "1\n" << a << ' ' << b << '\n';
    }
    else {
        cout << "2\n" << 1 << ' ' << b-1 << '\n'  << a << ' ' << b << '\n';
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





