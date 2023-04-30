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
// b^2 - 4ac -> b = b - k, (b - k)^2 < 4ac -> b^2 - 2kb + k^2 < 4ac -> 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> line(n);
    for (auto &u : line) cin >> u;
    sort(line.begin(), line.end());
    for (int i = 0; i < m; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll dc = 4 * a * c;
        if (dc < 0) {
           cout << "no\n";
           continue;
        }
        auto L = lower_bound(line.begin(), line.end(), b);
        auto R = lower_bound(line.begin(), line.end(), b);
        if (L == line.end()) --L;
        if (R == line.end()) --R;
        while (*R >= b && R != line.begin()) {
            R--;
        }
        if ((b - *L) * (b - *L) < dc) {
            cout << "yes\n";
            cout << *L << '\n';
        }
        else if ((b - *R) * (b - *R) < dc) {
            cout << "yes\n";
            cout << *R << '\n';
        }
        else {
            cout << "no\n";
        }
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





