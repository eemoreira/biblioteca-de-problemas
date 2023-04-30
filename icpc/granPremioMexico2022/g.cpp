#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int n;
// 1 2 3
// 4 5 6
// 7 8 9

pair<int,int> ans(int i, int j, char type) {
    if (type == 'a') {
        return make_pair(j,i);
    }
    if (type == 'c') {
        return make_pair(n - j + 1, n - i + 1);
    }
    if (type == 'b') {
        return make_pair(i, n - j + 1);
    }
    return make_pair(n - i + 1, j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    map<string, char> f;
    auto calc = [&](const string& now) {
        pair<int,int> test = {1,1};
        for (int i = 0; i < 3; i++) {
            test = ans(test.first, test.second, now[i]);
            dbg(test);
        }
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            ok = ans(1,1,char(i + 'a')) == test;
            if (ok) {
                f[now] = char(i + 'a');
                break;
            }
        }
        assert(ok);
    };
    string now = "";
    while (q--) {
        char c;
        cin >> c;
        if (c == 'q') {
            int i,j;
            cin >> i >> j;
            pair<int,int> g = {i,j};
            dbg(now);
            for (int l = (int)now.size()-1; l >= 0; l--) {
                g = ans(g.first, g.second, now[l]);
                dbg(g);
            }
            cout << 1LL * n * (g.first - 1)  + g.second << '\n';
        }
        else {
            char t;
            cin >> t;
            if ((int)now.size() == 3) {
                if (!f[now]) {
                    calc(now);
                }
                dbg(now, f[now]);
                now = f[now];
            }
            dbg(now);
            now += t;
        }
    }
}






