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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0) {
                a[l] = (a[l + 1] - 1 + m) % m;
                l--;
            }
            while (r < n) {
                a[r] = (a[r - 1] + 1) % m;
                r++;
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
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





