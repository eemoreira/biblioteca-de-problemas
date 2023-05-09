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
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
vector<int> adj[maxn];
ll sz[maxn], dad[maxn];

void dfs(int v, int p = -1) {
    sz[v] = 1;
    dad[v] = p;
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

ll inv(ll a) {
    int e = mod - 2;
    ll ans = 1;
    a %= mod;
    while (e) {
        if (e & 1) ans = ans * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return ans % mod;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    sz[0] = 0;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        sz[i] = 0;
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    if (k == 2) {
        dfs(0);
        const ll all = n * (n - 1) / 2;
        ll den = 0;
        for (int i = 0; i < n; i++) {
            ll now = all;
            bool ok = false;
            for (auto u : adj[i]) {
                if (sz[u] > sz[i]) {
                    ok = true;
                    continue;
                }
                now -= sz[u] * (sz[u] - 1) / 2;
            }
            if (ok) {
                ll size = n - sz[i];
                dbg(size);
                now -= size * (size - 1) / 2;
            }
            dbg(now);
            den = (den + now + mod) % mod;
        }
        cout << den * inv(n * (n - 1) / 2) % mod << '\n';
    }
    else {
        cout << 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
