#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i * i <= n + 2; i++) {
        int l = i, r = n;
        int now = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (i * mid <= n) {
                now = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (now != -1) {
            now -= i;
            ans += 2 * now + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

