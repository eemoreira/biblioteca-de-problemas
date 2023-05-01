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

const int maxn = 1e6 + 5;
int g[maxn];
int l, r;

int grundy(int x) {
    if (g[x] != -1) return g[x];
    set<int> s;
    for (int i = 2; i <= x; i++) {
        s.emplace(grundy(i - 2) ^ grundy(x - i));
    }
    int t = 0;
    for (auto u : s) {
        if (u != t) return g[x] = t;
        t++;
    }
    return g[x] = (int)s.size();
}

// grundy(x) = (x % (l + r)) / l

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    memset(g, -1, sizeof(g));
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += grundy(i) == 0;
        /* dbg(i, grundy(i)); */
        if (i % 50 == 0) {
            dbg(i, ans);
        }
    }
    cout << ans << '\n';
}





