#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> i3;

struct dsu {
    int n;
    vector<int> p, sz;
    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int v) {
        return v == p[v] ? v : (p[v] = find(p[v]));
    }
    bool unite(int v, int u) {
        v = find(v);
        u = find(u);
        if (sz[v] < sz[u]) swap(v, u);
        if (v != u) {
            sz[v] += sz[u];
            p[u] = v;
            sz[u] = 0;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i3> e;
    for (int i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        --v; --u;
        e.emplace_back(w, v, u);
    }
    sort(e.begin(), e.end());
    dsu d(n);
    ll ans = 0;
    ll mx = 0;
    for (auto [w, v, u] : e) {
        if (d.unite(v, u)) {
            mx = max(mx, w);
            ans += w;
        }
    }
    cout << ans - mx << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

