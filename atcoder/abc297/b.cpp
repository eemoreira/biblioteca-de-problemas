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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int x = -1, y = -1;
    int l = -1, k = -1, r = -1;
    for (int i = 0; i < 8; i++) {
        if (s[i] == 'B') {
            if (x == -1) x = i & 1;
            else y = i & 1;
        }
        if (s[i] == 'R') {
            if (l == -1) l = i;
            else r = i;
        }
        if (s[i] == 'K') {
            k = i;
        }
    }
    cout << (x + y == 1 && l < k && k < r ? "Yes\n" : "No\n");
}





