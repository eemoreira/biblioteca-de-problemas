#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i];
    }
    ll ans = 0;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        int now = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid] - p[i-1] <= s) {
                now = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        l = i, r = n;
        int t = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid] - p[i-1] < s) {
                t = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

        }
        if (now != -1 && p[now] - p[i-1] == s) ans += now - t;
    }
    cout << ans << '\n';
}





