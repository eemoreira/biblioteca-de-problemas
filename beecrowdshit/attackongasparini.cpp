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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, p, m, g;
    string s;
    cin >> n >> x;
    cin >> s;
    cin >> p >> m >> g;
    vector<int> a = {x};
    vector<int> ptrs(3);
    for (int i = 0; i < n; i++) {
        int now;
        int y = 0;
        if (s[i] == 'P') now = p, y = 0;
        else if (s[i] == 'M') now = m, y = 1;
        else now = g, y = 2;
        int& ptr = ptrs[y];
        while (ptr < (int)a.size() && a[ptr] < now) {
            ptr++;
        }
        if (ptr < (int)a.size()) a[ptr] -= now;
        else {
            a.emplace_back(x - now);
        }
    }
    cout << a.size() << '\n';
}





