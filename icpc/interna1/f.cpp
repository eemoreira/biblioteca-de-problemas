#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int MAX = 1e5 + 50;
vector<int> adj[MAX];
typedef tuple<int,int,int> i3;
typedef long long ll;
#define int ll
#define f first
#define s second
#define LINF 1e18

namespace seg {
	struct node {
		int tam;
		ll sum, lazy; // lazy pra soma
		ll mi1, mi2, mi; // mi = #mi1
		ll ma1, ma2, ma; // ma = #ma1

		node(ll x = 0) {
			sum = mi1 = ma1 = x;
			mi2 = LINF, ma2 = -LINF;
			mi = ma = tam = 1;
			lazy = 0;
		}
		node(const node& l, const node& r) {
			sum = l.sum + r.sum, tam = l.tam + r.tam;
			lazy = 0;
			if (l.mi1 > r.mi1) {
				mi1 = r.mi1, mi = r.mi;
				mi2 = min(l.mi1, r.mi2);
			} else if (l.mi1 < r.mi1) {
				mi1 = l.mi1, mi = l.mi;
				mi2 = min(r.mi1, l.mi2);
			} else {
				mi1 = l.mi1, mi = l.mi+r.mi;
				mi2 = min(l.mi2, r.mi2);
			}
			if (l.ma1 < r.ma1) {
				ma1 = r.ma1, ma = r.ma;
				ma2 = max(l.ma1, r.ma2);
			} else if (l.ma1 > r.ma1) {
				ma1 = l.ma1, ma = l.ma;
				ma2 = max(r.ma1, l.ma2);
			} else {
				ma1 = l.ma1, ma = l.ma+r.ma;
				ma2 = max(l.ma2, r.ma2);
			}
		}
		void setmin(ll x) {
			if (x >= ma1) return;
			sum += (x - ma1)*ma;
			if (mi1 == ma1) mi1 = x;
			if (mi2 == ma1) mi2 = x;
			ma1 = x;
		}
		void setmax(ll x) {
			if (x <= mi1) return;
			sum += (x - mi1)*mi;
			if (ma1 == mi1) ma1 = x;
			if (ma2 == mi1) ma2 = x;
			mi1 = x;
		}
		void setsum(ll x) {
			mi1 += x, mi2 += x, ma1 += x, ma2 += x;
			sum += x*tam;
			lazy += x;
		}
	};

	node seg[4*MAX];
	int n, *v;

	node build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l]};
		int m = (l+r)/2;
		return seg[p] = {build(2*p, l, m), build(2*p+1, m+1, r)};
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (l == r) return;
		for (int k = 0; k < 2; k++) {
			if (seg[p].lazy) seg[2*p+k].setsum(seg[p].lazy);
			seg[2*p+k].setmin(seg[p].ma1);
			seg[2*p+k].setmax(seg[p].mi1);
		}
		seg[p].lazy = 0;
	}
	pair<pair<ll, ll>, ll> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return {{LINF, -LINF}, 0};
		if (a <= l and r <= b) return {{seg[p].mi1, seg[p].ma1}, seg[p].sum};
		prop(p, l, r);
		int m = (l+r)/2;
		auto L = query(a, b, 2*p, l, m), R = query(a, b, 2*p+1, m+1, r);
		return {{min(L.f.f, R.f.f), max(L.f.s, R.f.s)}, L.s+R.s};
	}
	node updatemin(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p].ma1 <= x) return seg[p];
		if (a <= l and r <= b and seg[p].ma2 < x) {
			seg[p].setmin(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatemin(a, b, x, 2*p, l, m),
						updatemin(a, b, x, 2*p+1, m+1, r)};
	}
	node updatemax(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p].mi1 >= x) return seg[p];
		if (a <= l and r <= b and seg[p].mi2 > x) {
			seg[p].setmax(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatemax(a, b, x, 2*p, l, m),
						updatemax(a, b, x, 2*p+1, m+1, r)};
	}
	node updatesum(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p].setsum(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatesum(a, b, x, 2*p, l, m),
						updatesum(a, b, x, 2*p+1, m+1, r)};
	}
};

namespace hld {
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) { return a + b; } // how to merge paths
    void dfs_sz(int u, int p=-1) {
        sz[u] = 1;
        for (auto &v : adj[u]) if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
        }
    }
    void dfs_hld(int u, int p=-1) {
        pos[u] = t++;
        for (int v : adj[u]) if (v != p) {
            pai[v] = u;
            head[v] = (v == adj[u][0] ? head[u] : v);
            dfs_hld(v, u);
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<ll>& v) {
        build(root);
        int aux[MAX];
        for (int i = 0; i < MAX; i++) aux[i] = 0;
        for (int i = 0; i < (int)v.size(); i++) aux[pos[i]] = v[i];
        seg::build((int)v.size(), aux);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) return seg::query(pos[u]+e, pos[v]).second;
        else {
            ll qv = seg::query(pos[head[v]], pos[v]).second;
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) seg::updatemax(pos[u]+e, pos[v], k);
        else {
            seg::updatemax(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) {
        return seg::query(pos[u], pos[u]+sz[u]-1).second;
    }
}

namespace st {
    int n, me;
    vector<vector<int>> up;
    vector<int> d;
    void bl_dfs(int v, int p) {
        up[v][0] = p;
        for(int i = 1; i <= me; i++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for(int u : adj[v]){
            if(u != p){
                d[u] = d[v] + 1;
                bl_dfs(u, v);
            }
        }
    }
    void build(int _n, int root){
        n = _n;
        me = __lg(n) + 1;
        up.assign(n, vector<int>(me+1, 0));
        d.assign(n, 0);
        bl_dfs(root, root);
    }
    int ancestor(int v, int k){ // k-th ancestor of u 
        for(int i = me; i >= 0; i--){
            if((1 << i) & k){
                v = up[v][i];
            }
        }
        return v;
    }
    int depth(int v) {
        return d[v];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int v;
        cin >> v;
        --v;
        adj[i + 1].emplace_back(v);
        adj[v].emplace_back(i + 1);
    }
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    hld::build(0, a);
    st::build((int)a.size(), 0);
    while (q--) {
        int o;
        cin >> o;
        if (!o) {
            int u,k,w;
            cin >> u >> k >> w;
            --u;
            int v = st::ancestor(u, k - 1);
            dbg(u, v);
            hld::update(u, v, w);
        }
        else {
            int v;
            cin >> v;
            v--;
            cout << hld::query_subtree(v) << '\n';
        }
    }
}





