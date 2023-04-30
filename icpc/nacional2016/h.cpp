#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    ll ans = 0;
    multiset<int> pq;
    int y = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        if (y == k) {
            pq.emplace(a[i]);
            y = 0;
        }
        else if (!pq.empty() && a[i] > *pq.begin()){
            y++;
            pq.erase(pq.begin());
            pq.emplace(a[i]);
        }
        else {
            y++;
        }
    }
    while (!pq.empty()) {
        ans -= *pq.begin();
        pq.erase(pq.begin());
    }
    cout << ans << '\n';
}





