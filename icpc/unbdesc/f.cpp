#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 86;

vector<ll> pa(maxn), pb(maxn), p(maxn), f(maxn), fa(maxn), fb(maxn);

// b a ab aba abaab abaababa abaababaabaab

ii go(ll it, int n) {
    if (n == 0) return ii(0, 1);
    if (n == 1) return ii(1, 0);
    dbg(it, n, p[n], f[n]);
    if (it == p[n]) {
        return ii(fa[n], fb[n]);
    }
    if (it > p[n - 1] + f[n - 1]) {
        dbg(p[n - 1], f[n - 1]);
        ii now = go(it - 2 * f[n - 1] - f[n - 2], n - 2);
        return ii(fa[n - 1] + now.first, fb[n - 1] + now.second);
    }
    return go(it - f[n - 1], n - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;

    fa[0] = pa[0] = 0;
    fa[1] = pa[1] = 1;
    fb[0] = pb[0] = 1;
    pb[1] = 1;

    f[0] = 1;
    p[0] = 1;
    f[1] = 1;
    p[1] = 2;
    for (int i = 2; i < maxn && p[i-1] <= (ll)1e18; i++) {
        f[i] = f[i-1] + f[i-2];
        fa[i] = fa[i-1] + fa[i-2];
        fb[i] = fb[i-1] + fb[i-2];
        p[i] = p[i-1] + f[i];
        pa[i] = pa[i-1] + fa[i];
        pb[i] = pb[i-1] + fb[i];
    }
    for (int i = 0; i < maxn; i++) p[i]--;
    dbg(p);
    int fl = -1, fr = -1;
    for (int i = 0; i < maxn; i++) {
        if (p[i] >= l-1 && fl == -1) {
            fl = i;
        }
        if (p[i] >= r && fr == -1) {
            fr = i;
        }
    }
    dbg(fl, fr);
    ii L = (l == 0 ? ii(0,0) : go(l - 1, fl));
    if (fl > 0) {
        L.first += pa[fl - 1];
        L.second += pb[fl - 1];
    }

    ii R = go(r, fr);
    if (fr > 0) {
        R.first += pa[fr - 1];
        R.second += pb[fr - 1];
    }

    dbg(L, R);
    ii ans = ii(R.first - L.first, R.second - L.second);
    cout << ans.first << ' ' << ans.second << '\n';
}





