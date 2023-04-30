#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int pa = 0, pb = 0;
    while (pa < n && pb < m) {
        if (abs(b[pb] - a[pa]) <= k) {
            ans++;
            pb++;
            pa++;
        } 
        else if (b[pb] > a[pa] + k) {
            pa++;
        }
        else {
            pb++;
        }
    }
    cout << ans << '\n';
}





