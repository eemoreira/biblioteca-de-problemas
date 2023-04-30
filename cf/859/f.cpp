#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n, m, sx, sy, fx, fy;
    cin >> n >> m >> sx >> sy >> fx >> fy;
    map<pair<int,int>, map<int,int>> vis;
    string mv;
    cin >> mv;
    pair<int,int> now = {sx,sy};
    int ans = 0;
    bool ok = false;
    int going = 0;
    if (mv == "UR") vis[now][1] = 1, going = 1;
    else if (mv == "UL") vis[now][2] = 1, going = 2;
    else if (mv == "DR") vis[now][3] = 1, going = 3;
    else vis[now][4] = 1, going = 4;
    bool t = true;
    auto change = [&](int x, int y, int mxx, int mxy, int mnx, int mny) {
        if (going == 1) {
            int difu = x - mnx;
            int difr = mxy - y;
            int mn = min(difu, difr);
            if (mn < 0) {
                return make_pair(-1,-1);
            }
            return make_pair(x - mn, y + mn);
        }
        if (going == 2) {
            int difu = x - mnx;
            int difl = y - mny;
            int mn = min(difu, difl);
            if (mn < 0) {
                return make_pair(-1,-1);
            }
            return make_pair(x - mn, y - mn);
        }
        if (going == 3) {
            int difd = mxx - x;
            int difr = mxy - y;
            int mn = min(difd, difr);
            if (mn < 0) {
                return make_pair(-1,-1);
            }
            return make_pair(x + mn, y + mn);
        }
        int difd = mxx - x;
        int difl = y - mny;
        int mn = min(difd, difl);
        if (mn < 0) {
            return make_pair(-1,-1);
        }
        return make_pair(x + mn, y - mn);
    };
    /* UR -> 1 */
    /* UL -> 2 */
    /* DR -> 3 */
    /* DL -> 4 */
    while (t || !vis[now][going]) {
        pair<int,int> nx = change(now.first, now.second, n, m, 1, 1);
        pair<int,int> check = change(now.first, now.second, fx, fy, fx, fy);
        dbg(now, nx, check, going);
        if (check.first == fx && check.second == fy) {
            ok = true;
            break;
        }
        ans++;
        vis[now][going] = 1;
        if (going == 1) {
            if (nx.first == 1 && nx.second == m) {
                going = 4;
            }
            else if (nx.first == 1) {
                going = 3;
            }
            else {
                going = 2;
            }
        }
        else if (going == 2) {
            if (nx.first == 1 && nx.second == 1) {
                going = 3;
            }
            else if (nx.first == 1) {
                going = 4;
            }
            else {
                going = 1;
            }
        }
        else if (going == 3) {
            if (nx.first == n && nx.second == m) {
                going = 2;
            }
            else if (nx.first == n) {
                going = 1;
            }
            else {
                going = 4;
            }
        }
        else if (going == 4) {
            if (nx.first == n && nx.second == 1) {
                going = 1;
            }
            else if (nx.first == n) {
                going = 2;
            }
            else {
                going = 3;
            }
        }
        t = false;
        now = nx;
    }
    cout << (ok ? ans : -1) << '\n';
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





