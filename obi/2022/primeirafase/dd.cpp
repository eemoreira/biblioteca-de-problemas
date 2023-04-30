#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s;
    cin >> n >> s;
    vector<ll> p(n + 1);
    map<int,int> f;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll now = p[i] - s;
        ans += f[now];
        f[p[i]]++;
    }
    cout << ans << '\n';
}





