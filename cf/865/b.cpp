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
const int maxn = 2e5 + 5;
int ans[10][maxn];

void solve() {
    int n;
    cin >> n;
    ans[0][0] = 2 * n;
    ans[1][n-1] = 2 * n - 1;
    set<int> pq;
    for (int i = 1; i < 2 * n - 1; i++) pq.emplace(i);
    for (int j = 1; j < n; j++) {
        assert((int)pq.size() > 1);
        if (j & 1) {
            ans[1][j-1] = *pq.begin();
            pq.erase(pq.begin());
            ans[0][j] = *pq.begin();
            pq.erase(pq.begin());
        }
        else {
            ans[0][j] = *pq.rbegin();
            pq.erase(--pq.end());
            ans[1][j-1] = *pq.rbegin();
            pq.erase(--pq.end());
        }
        if (n % 4) {
            swap(ans[0][j], ans[1][j-1]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
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





