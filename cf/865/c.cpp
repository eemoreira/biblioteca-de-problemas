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

bool check(int n, vector<ll> a) {
    for (int i = n - 2; i > 0; i--) {
        a[i - 1] += a[i + 1] - a[i];
        a[i] = a[i + 1];
    }
    dbg(a);
    if (a[0] <= a[1] || n % 2) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &u : a) {
        cin >> u;
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << "yes\n";
    }
    else if (check(n,a)) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}





