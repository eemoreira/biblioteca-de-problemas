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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> f;
    for (auto &u : a) {
        cin >> u;
        f[u]++;
    }
    int mex = 0;
    while (f[mex]) mex++;
    bool ok = true;
    int end = -1;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == mex + 1) {
            end = i;
            if (start == -1) start = i;
        }
    }
    dbg(mex, end, start);
    if (end == -1) {
        ok = false;
        for (auto u : f) ok |= u.second > 1 || u.first > mex + 1;
    }
    else {
        for (int i = start; i <= end; i++) {
            if (a[i] >= mex + 1) continue;
            f[a[i]]--;
            if (!f[a[i]]) ok = false;
        }
    }
    cout << (ok ? "yes\n" : "no\n");
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





