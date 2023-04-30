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
    int n;
    cin >> n;
    vector<int> b(n-1);
    for (auto &u : b) cin >> u;
    vector<int> a(n);
    a[n-1] = b[n-2];
    for (int i = n - 2; i > 0; i--) {
        if (b[i-1] <= b[i]) {
            a[i] = b[i-1];
        }
        else {
            a[i] = b[i];
            a[i-1] = b[i-1];
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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





