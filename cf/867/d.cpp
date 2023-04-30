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

/* stop freaking out pls */
// all mods from[0, n -1] with prefixes

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << (n == 1 ? 1 : -1) << '\n';
        return;
    }
    vector<int> ans(n);
    ans[0] = n;
    ans[n - 1] = 1;
    int y = n - 1;
    for (int i = 1; i < n - 1; i++) {
        ans[i] = i & 1 ? n - i : i;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}





