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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 1; i < n; i++) {
        ll now = i * x;
        multiset<ll> pq;
        for (int j = n - i; j < n; j++) {
            pq.emplace(a[j]);
        }
        for (int j = 0; j < n; j++) {
            pq.emplace(a[j]);
            now += *pq.begin();
            auto it = pq.find(a[(j - i + n) % n]);
            pq.erase(it);
        }
        ans = min(ans, now);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





