#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

class dsu {
public:
    vector<int> p;
    int n;
    vector<int> sz;
    dsu(int _n) : n(_n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
    inline int get(int x){
        return x == p[x] ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x != y){
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dsu d(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --v; --u;
        d.unite(v, u);
    }
    set<int> comp;
    for (int i = 0; i < n; i++) {
        comp.emplace(d.get(i));
    }
    cout << comp.size() - 1 << '\n';
    int t = *comp.begin();
    comp.erase(comp.begin());
    for (auto u : comp) {
        cout << t+1 << ' ' << u+1 << '\n';
    }
}





