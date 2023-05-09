#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[11];

void solve() {
    ll n;
    cin >> n;
    string d;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        while (x--) {
            d += char('0' + i);
        }
    }
    if (d.back() == '0') {
        cout << 1 << '\n';
        return;
    }
    ll ans = 0;
    do {
        ll now = stoll(d);
        if (now <= n) ans++;
    } while(next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] *= i;
}

