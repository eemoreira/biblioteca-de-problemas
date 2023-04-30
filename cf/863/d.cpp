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
ll f[50];
map<ll, int> have;
ll n, x, y;

bool go(int ptr, bool dir) {
    if (ptr == 0) return true;
    if (dir) {
        if (y > f[ptr]) y -= f[ptr];
        else if (y > f[ptr - 1]) {
            return false;
        }
    }
    else {
        if (x > f[ptr]) x -= f[ptr];
        else if (x > f[ptr - 1]) {
            return false;
        }
    }
    dir ^= 1;
    return go(ptr - 1, dir);
}

void solve() {
    cin >> n >> x >> y;
    cout << (go(n + 1, 0) ? "yes\n" : "no\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = f[1] = 1;
    have[1] = 2;
    for (int i = 2; i < 50; i++) {
        f[i] = f[i-1] + f[i-2];
        have[f[i]] = 2;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





