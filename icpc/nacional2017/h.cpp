#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

/* stop freaking out pls */
void solve() {
    ll a, b, c;
    ll x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    cout << max(0ll, x - a) + max(0ll, y - b) + max(0ll, z - c) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}





