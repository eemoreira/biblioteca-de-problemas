#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 5e6 + 50;
int euler[maxn];

int lim, mx;
vector<int> adj[maxn];
int up[maxn][6], d[maxn];
int vis[maxn];

void Pre_dfs(int v, int p){
    up[v][0] = p;
    vis[v] = 1;
    for(int i = 1; i <= lim; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : adj[v]){
        if (!vis[u]) {
            d[u] = d[v] + 1;
            Pre_dfs(u,v);
        }
    }
}

int LCA(int u, int v){
    if (d[u] < d[v]) {
        swap(u,v);
    }
    int k = d[u] - d[v];
    for (int i = lim; ~i; i--) {
        if (k >> i & 1) {
            u = up[u][i];
        }
    }
    if (u == v) return v;
    for (int i = lim; ~i; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void preprocess(int root) {
    lim =  __lg(mx) + 1;
    Pre_dfs(root, root);
}

int Get_dist(int v, int u) {
    return d[v] + d[u] - 2 * d[LCA(u,v)];
}

struct node {
    int ans, lca, l, r;
    node(int _ans, int _lca,int _l, int _r) : ans(_ans), lca(_lca), l(_l), r(_r) {
    }
    node() {
        ans = lca = l = r = 0;
    }
};

node merge(node a, node b) {
    node ret;
    if (a.lca < 0) ret.lca = b.lca;
    else if (b.lca < 0) ret.lca = a.lca;
    else ret.lca = LCA(a.lca, b.lca);
    ret.ans = a.ans + b.ans;
    int d1 = (a.lca < 0 ? 0 : Get_dist(a.lca, ret.lca));
    int d2 = (b.lca < 0 ? 0 : Get_dist(b.lca, ret.lca));
    ret.ans += (a.r - a.l + 1) * d1;
    ret.ans += (b.r - b.l + 1) * d2;
    /* assert(a.r < b.l); */
    ret.l = min(a.l, b.l);
    ret.r = max(a.r, b.r);
    return ret;
}

const node neutral = node(0,-1,1e9,-1e9);

template<typename T>
struct Seg {
    vector<T> t;
    int n;
    void update(int i, T v) {
        for (t[i += n] = v; i >>= 1;) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }
    T query(int l, int r) {
        T ansl = neutral;
        T ansr = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, t[l++]);
            if (r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr);
    }
    Seg(vector<T> &a) {
        n = a.size();
        t.assign(n << 1, neutral);
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (int i = n-1; i > 0; i--) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < maxn; i++) {
        euler[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (euler[i] == i) {
            for (int j = i; j < maxn; j+=i) {
                euler[j] -= euler[j] / i;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<node> t(n, neutral);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = node(0, a[i], i+1, i+1);
        s.emplace(i);
    }
    for (int i = 0; i < n; i++) {
        int w = a[i];
        int cnt = 1;
        while (w > 1) {
            adj[w].emplace_back(euler[w]);
            adj[euler[w]].emplace_back(w);
            cnt++;
            w = euler[w];
        }
        mx = max(mx, cnt);
    }
    preprocess(1);
    Seg<node> seg(t);
    s.emplace(-1e9);
    s.emplace(1e9);
    while (q--) {
        int o, A, B;
        cin >> o >> A >> B;
        A--; B--;
        if (o == 1) {
            auto l = s.lower_bound(A);
            if (l == s.end()) --l;
            auto r = s.upper_bound(B);
            vector<int> remove;
            while (l != r) {
                int p = *l;
                dbg(A, B, p);
                a[p] = euler[a[p]];
                seg.update(p, node(0,a[p],p+1,p+1));
                if (a[p] == 1) {
                    remove.emplace_back(p);
                }
                l++;
            }
            for (auto u : remove) s.erase(u);
        }
        else {
            cout << seg.query(A,B+1).ans << '\n';
        }
    }
}





