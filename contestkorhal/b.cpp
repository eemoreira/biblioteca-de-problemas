#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace seg {
    const ll ESQ = 0, DIR = 5e4 + 50;
	struct node {
        ll v = 0;
        node *l = NULL, *r = NULL;
        node() {}
        node(ll v) : v(v) {}
        node(node* l, node* r) : l(l), r(r) { v = l->v + r->v; }
        void apply() {
            if(l == NULL) l = new node();
            if(r == NULL) r = new node();
        }
	};
    vector<node*> roots;
    void build() { roots.push_back(new node()); }
    void push(node* n, int esq, int dir) { if (esq != dir) n->apply(); }
    // change x value to v
    node* update(node* n, int esq, int dir, int x, int v) {
        push(n, esq, dir);
        if (esq == dir) return new node(n->v + v);
        int mid = (esq + dir)/2;
        if (x <= mid) return new node(update(n->l, esq, mid, x, v), n->r);
        else return new node(n->l, update(n->r, mid+1, dir, x, v));
    }
    int update(int root, int pos, int val) {
        node* novo = update(roots[root], ESQ, DIR, pos, val);
        roots.push_back(novo);
        return roots.size() - 1;
    }
    // sum in [L, R]
    ll query(node* L, node* R, int esq, int dir, int l, int r) {
        push(L, esq, dir);
        push(R, esq, dir);
        if (esq > r || dir < l) return 0;
        if (l <= esq && dir <= r) return abs(R->v - L->v);
        int mid = (esq + dir)/2;
        return query(L->l, R->l, esq, mid, l, r) + query(L->r, R->r, mid+1, dir, l, r);
    }
    ll query(int L, int R, int l, int r) {
        return query(roots[L], roots[R], ESQ, DIR, l, r);
    }
    // kth min number in [L, R]
    int kth(node* L, node* R, int esq, int dir, int k) {
        push(L, esq, dir);
        push(R, esq, dir);
        if (esq == dir) return esq;
        int mid = (esq + dir)/2;
        int cont = L->l->v - R->l->v;
        if (cont >= k) return kth(L->l, R->l, esq, mid, k);
        else return kth(L->r, R->r, mid+1, dir, k-cont);
    }
    int kth(int l_root, int r_root, int k) {
        return kth(roots[r_root], roots[l_root], ESQ, DIR, k);
    }
};

const int N = 5e4 + 50;
int adj[N], ans[N], vis[N];
int n,q;
vector<int> go;

int dfs(int v) {
    vis[v]++;
    ans[v] = min(ans[v], v + 1);
    if (vis[adj[v]] < 2) {
        ans[v] = min(ans[v], dfs(adj[v]));
    }
    else {
        ans[v] = min(ans[v], ans[adj[v]]);
    }
    return ans[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        --adj[i];
        ans[i] = 1e9;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] < 2) {
            dfs(i);
        }
    }
    seg::build();
    for (int i = 0; i < n; i++) {
        seg::update(i, ans[i], 1);
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l;
        int size = r - l;
        int v = seg::kth(l, r, (size >> 1) ? (size >> 1) : 1);
        long long posV = seg::query(r, l, 1, v);
        long long posU = seg::query(r, l, 1, v - 1);
        int u = seg::kth(l, r, posU);
        if (u == 0) u = 1;
        if (abs(size - 2 * posU) <= abs(size - 2 * posV)) {
            cout << u << '\n';
        }
        else {
            cout << v << '\n';
        }
    }
}





