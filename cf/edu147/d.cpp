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
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        sum += r[i] - l[i] + 1;
    }
    if (sum < k) {
        cout << -1 << '\n';
        return;
    }
    sum = 0;
    multiset<ll> pq;
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        pq.emplace(r[i] - l[i] + 1);
        sum += r[i] - l[i] + 1;
        while (!pq.empty() && sum >= k) {
            ll last = r[i] - (sum - k);
            ans = min(ans, 2LL * (int)pq.size() + last);
            sum -= *pq.begin();
            pq.erase(pq.begin());
        }
        dbg(ans);
    }
    cout << ans << '\n';
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





