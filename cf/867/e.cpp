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
    string s;
    cin >> n >> s;
    vector<int> F(26);
    for (auto &u : s) F[u - 'a']++;
    if (n % 2 == 1 || *max_element(F.begin(), F.end()) > n >> 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> cnt(26);
    for (int i = 0; i < n >> 1; i++) {
        if (s[i] == s[n - 1 - i]) {
            cnt[s[i] - 'a']++;
        }
    }
    int ans = 0;
    multiset<ii> pq;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        pq.emplace(cnt[i], i);
    }
    dbg(pq);
    while ((int)pq.size() > 1) {
        auto [q0, c0] = *pq.begin();
        auto [q1, c1] = *pq.rbegin();
        pq.erase(make_pair(q0,c0));
        if (q0 == 0) continue;
        pq.erase(make_pair(q1, c1));
        pq.emplace(q0 - 1, c0);
        pq.emplace(q1 - 1, c1);
        ans++;
    }
    if (!pq.empty()) ans += pq.begin()->first;
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





