#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int MX = 1e8;
bool f[MX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(15);
    p[0] = 1;
    for (int i = 1; i < 10; i++) {
        p[i] = p[i-1] * 10;
    }
    if (s == string(1, '0')) {
        cout << 1 << '\n';
        return 0;
    }
    if (s[0] == '0' && n) {
        cout << 0 << '\n';
        return 0;
    }
    function<void(int,int,int)> calc = [&](int id, int bit, int X) {
        /* dbg(id, n - 1 - id, bit, X); */
        if (id >= n) {
            f[bit] = true;
            return;
        }
        if (s[n-1-id] != '_' && s[n-1-id] != 'X') {
            calc(id+1,  bit + p[id] * (int)(s[n-1-id] - '0'), X);
        }
        else if (s[n-1-id] == 'X' && ~X) {
            if (X == 0 && id == n - 1) return;
            calc(id+1, bit + p[id] * X, X);
        }
        else {
            for (int i = id == n - 1; i < 10; i++) {
                if (s[n-1-id] == 'X') X = i;
                calc(id + 1, bit + p[id] * i, X);
            }
        }
    };
    if (s == string(8, '_')) {
        int ans = 0;
        cout << MX / 25 - MX / 250 << '\n';
    }
    else {
        if (s.back() != '_' && s.back() != 'X') {
            calc(1,s.back() -'0',-1);
        }
        else {
            for (int j = 0; j < 10; j++) {
                calc(1, j, s.back() == 'X' ? j : -1);
            }
        }
        int ans = 0;
        for (int i = 0; i < MX; i += 25) {
            ans += f[i];
        }
        cout << ans << '\n';
    }
}





