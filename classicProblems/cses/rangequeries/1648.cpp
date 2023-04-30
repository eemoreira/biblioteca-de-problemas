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
ll seg[2 * maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = n; i < n << 1; i++) {
        cin >> seg[i];
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
    while (q--) {
        int o;
        cin >> o;
        if (o == 2) {
            int l, r;
            cin >> l >> r;
            ll ans = 0;
            for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) ans += seg[l++];
                if (r & 1) ans += seg[--r];
            }
            cout << ans << '\n';
        }
        else {
            ll v, p;
            cin >> p >> v;
            for (seg[p += n - 1] = v; p >>= 1;) {
                seg[p] = seg[p << 1] + seg[p << 1 | 1];
            }
        }
    }
}





