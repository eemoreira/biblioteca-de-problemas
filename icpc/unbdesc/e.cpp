#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int d = __lg((ll)1e18);
const int mod = 1e9 + 7;
ll basis[70];

int insertVector(ll mask) {
    for (int i = 0; i < d; i++) {
        if (!(mask >> i & 1)) continue;
        if (!basis[i]) {
            basis[i] = mask;
            return 1;
        }
        mask ^= basis[i];
    }
    return 0;
}

ll bpw(ll a, ll e) {
    a %= mod;
    ll ans = 1;
    while (e) {
        if (e & 1) ans = ans * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dbg(d);
    int base = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        base += insertVector(x);
    }
    cout << (bpw(2, n) - bpw(2, n - base) + mod) % mod << '\n';
}





