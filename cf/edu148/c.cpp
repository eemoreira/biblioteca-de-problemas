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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            break;
        }
        if (a[i] == a[i + 1]) {
            bool ok = i == 0;
            while (i < n - 1 && a[i] == a[i + 1]) i++;
            ok &= i == n - 1;
            if (ok) {
                cout << 1 << '\n';
                return;
            }
            i--;
            continue;
        }
        else if (a[i] < a[i + 1]) {
            while (i < n - 1 && a[i] <= a[i + 1]) {
                i++;
            }
            i--;
        }
        else {
            while (i < n - 1 && a[i] >= a[i + 1]) {
                i++;
            }
            i--;
        }
        dbg(i);
        ans++;
    }
    cout << ans << '\n';
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





