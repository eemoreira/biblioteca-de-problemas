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
 
const int maxn = 2e5 + 5;
ll f[maxn];
int n, q;
 
ll rsq(int i) {
    ll ans = 0;
    while (i) {
        ans += f[i];
        i -= (i & -i);
    }
    return ans;
}
 
void update(int i, ll v) {
    while (i <= n) {
        f[i] += v;
        i += (i & -i);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        update(i, x);
        update(i + 1, -x);
    }
    while (q--) {
        int o;
        cin >> o;
        if (o == 2) {
            int i;
            cin >> i;
            cout << rsq(i) << '\n';
        }
        else {
            ll l, r, v;
            cin >> l >> r >> v;
            update(l, v);
            update(r + 1, -v);
        }
    }
}
