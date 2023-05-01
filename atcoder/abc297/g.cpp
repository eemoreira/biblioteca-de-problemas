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

const int maxn = 10000;
int g[maxn];
int l, r;

int brute(int x) {
    if (g[x] != -1) return g[x];
    set<int> s;
    for (int i = l; i <= min(r, x); i++) {
        s.emplace(brute(x - i));
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
    cin >> n >> l >> r;
    /* memset(g, -1, sizeof(g)); */
    /* for (int i = 0; i <= n; i++) { */
    /*     dbg(i, brute(i)); */
    /* } */
    int x = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        x ^= (v % (l + r)) / l;
    }
    cout << (x ? "First\n" : "Second\n");
}





