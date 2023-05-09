#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.emplace(x);
    }
    int ans = 0;
    while (!a.empty() && !b.empty()) {
        int now = *a.begin();
        a.erase(a.begin());
        auto lb = b.lower_bound(now);
        if (lb == b.begin()) continue;
        lb--;
        if (*lb < now) {
            ans++;
            b.erase(lb);
        }
    }
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

