#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,h,w;
    cin >> n >> h >> w;
    for (int i = 0; i < n; i++) {
        char c0, c1;
        cin >> c0 >> c1;
        bool home = c0 == 'Y';
        bool work = c1 == 'Y';
        if (home) {
            assert(h);
            cout << 'Y' << ' ';
            h--;
            w++;
        }
        else if (!w) {
            cout << 'Y' << ' ';
            h--;
            w++;
        }
        else {
            cout << 'N' << ' ';
        }
        if (work) {
            assert(w);
            cout << 'Y' << '\n';
            w--;
            h++;
        }
        else if (!h) {
            cout << 'Y' << '\n';
            h++;
            w--;
        }
        else {
            cout << 'N' << '\n';
        }
    }
}





