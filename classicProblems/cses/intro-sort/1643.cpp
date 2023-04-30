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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> p(n + 1), pmin(n + 1, 1e18);
    ll ans = -1e18;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
        pmin[i] = min(p[i], pmin[i-1]);
        ans = max({ans, p[i], p[i] - pmin[i - 1]});
    }
    cout << ans << '\n';
}





