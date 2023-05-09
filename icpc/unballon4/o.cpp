#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &u : a) {
        cin >> u;
        sum += u;
    }
    ll l = 0, r = 1e18;
    ll ans = sum;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll front = 0;
        int i = 0;
        for (i = 0; i < n; i++) {
            if (front + a[i] > mid) break;
            front += a[i];
        }
        ll back = 0;
        for (int j = n - 1; j > i; j--) {
            if (back + a[j] > mid) break;
            back += a[j];
        }
        if (sum - front - back <= mid) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

