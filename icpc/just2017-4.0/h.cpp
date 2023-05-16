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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mid = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            mid += a[i][j] - '0';
        }
    }
    int borda = 0;
    for (int i = 0; i < m; i++) {
        borda += a[0][i] - '0';
        borda += a[n - 1][i] - '0';
    }
    for (int i = 1; i < n - 1; i++) {
        borda += a[i][0] - '0';
        borda += a[i][m - 1] - '0';
    }
    dbg(borda, mid);
    if (mid < 2 * (n + m - 2) - borda) {
        cout << -1 << '\n';
    }
    else {
        cout << 2 * (n + m - 2) - borda << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





