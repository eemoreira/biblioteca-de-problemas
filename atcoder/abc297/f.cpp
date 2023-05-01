#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int maxn = 1e6 + 6;
const int mod = 998244353;
ll f[maxn], invf[maxn];


ll nCr(int n, int r) {
    return f[n] % mod * invf[n - r] % mod * invf[r] % mod;
}

ll invnCr(int n, int r) {
    return invf[n] % mod * f[n - r] % mod * f[r] % mod;
}

ll calc(int w, int h, int r) {
    if (w < 0) return 0ll;
    if (h < 0) return 0ll;
    if (w * h < r) return 0ll;
    return nCr(h * w, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * i % mod;
        invf[i] = 1;
        ll b = f[i];
        int e = mod - 2;
        while (e) {
            if (e & 1) {
                invf[i] = b * invf[i] % mod;
            }
            b = b * b % mod;
            e >>= 1;
        }
    }
    ll h, w, k;
    cin >> h >> w >> k;
    ll num = 0;
    ll den = invnCr(h * w, k);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (k > i * j) continue;
            ll x = i * j % mod * (h - i + 1) * (w - j + 1) % mod;
            ll y = calc(i, j, k);
            y = (y - 2 * calc(i - 1, j, k) % mod - 2 * calc(i, j - 1, k)) % mod;
            y = (y + 4 * calc(i - 1, j - 1, k) + calc(i - 2, j, k) + calc(i, (j - 2), k)) % mod;
            y = (y - 2 * calc(i - 2, j - 1, k) - 2 * calc(i - 1, j - 2, k)) % mod;
            y = (y + calc(i - 2, j - 2, k)) % mod;
            if (y < 0) y += mod;
            num = (num + y * x % mod) % mod;
        }
    }
    cout << num * den % mod << '\n';
}





