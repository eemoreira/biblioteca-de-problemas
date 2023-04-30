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

const int maxn = 5e5 + 5;
int f[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1;
    cin >> n;
    vector<ii> a(n);
    map<int,int> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        c[a[i].first];
        c[a[i].second];
    }
    for (auto &u : c) {
        u.second = k++;
    }
    for (auto &[u, v] : a) {
        u = c[u];
        v = c[v];
    }
    k++;
    for (int i = 0; i < n; i++) {
        f[a[i].first] = 1;
        f[a[i].second] = -1;
    }
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        f[i] += f[i-1];
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
}





