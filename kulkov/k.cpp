#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int mod = 1e9 + 9;
const int maxn = 1 << 20 | 5;
ll a[maxn];

void calc(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    dbg(l, r, mid);
    for (int i = l; i <= mid; i++) {
        a[i] -= a[i + mid + 1 - l] % mod;
    }
    calc(l, mid);
    calc(mid + 1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int s = 1 << n;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }
    calc(0, s-1);
    ll ans = 1;
    for (int i = 0; i < s; i++) {
        dbg(a[i]);
        ans = ans * a[i] % mod;
        if (ans < 0) ans += mod;
    }
    cout << ans % mod << '\n';
}




