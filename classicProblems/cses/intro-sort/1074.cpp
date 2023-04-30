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
    vector<ll> p(n + 1), suf(n + 2), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }
    suf[n] = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        suf[i] = suf[i + 1] + a[i - 1];
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, i * a[i] - p[i] + suf[i + 2] - (n - i - 1) * a[i]);
    }
    cout << ans << '\n';
}





