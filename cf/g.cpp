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

const int maxn = 2030;
ll a[maxn][maxn];
ll p[maxn * maxn];

void solve() {
    ll n;
    cin >> n;
    int x = 0;
    int l, r;
    for (int i = 0; i < maxn; i++) {
        if (a[i][1] + i - 1 >= n) {
            x = i;
            l = r = n - a[i][1] + 1;
            break;
        }
    }
    ll ans = 0;
    while (x) {
        ans += p[a[x][r]] - p[a[x][l] - 1];
        x--;
        if (l > 1) l--;
        if (r > x) r--;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cnt = 1;
    for (int i = 1; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = cnt; 
            p[cnt] = cnt * cnt + p[cnt - 1];
            cnt++;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





