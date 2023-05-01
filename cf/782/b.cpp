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
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ans(n);
    int y = k;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (y & 1) {
                if (k) {
                    k--;
                    ans[i] = 1;
                }
                else {
                    s[i] = '0';
                }
            }
        }
        else {
            if (!(y & 1)) {
                if (k) {
                    k--;
                    ans[i] = 1;
                    s[i] = '1';
                }
                else {
                    s[i] = '0';
                }
            }
            else {
                s[i] = '1';
            }
        }
    }
    if (k) {
        for (int i = 0; k && i < n; i++) {
            if ((ans[i] + k) % 2 != ans[i] % 2) {
                ans[i] += k - 1;
                k = 1;
            }
            else {
                ans[i] += k;
                k = 0;
            }
        }
    }
    if (k == 1) {
        ans.back()++;
        s[n - 1] = '0' + '1' - s[n - 1];
    }
    cout << s << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
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





