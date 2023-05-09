#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)  {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += max({0ll, a[i-1][j], a[i][j-1]});
        }
    }
    ll ans = -1e18;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

