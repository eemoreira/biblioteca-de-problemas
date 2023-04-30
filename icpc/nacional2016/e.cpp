#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;


const int neutral = 0; //comp(x, neutral) 
const int MAXN = 1e5 + 5;
const int MAXS = 4 * MAXN * 30; 
#define comp(a, b) ((a)+(b))

int nds, st[MAXS], ls[MAXS], rs[MAXS];
int vroot[MAXN];

class persistentSeg {
    private:
        int size, nds, nv;
        int newnode() {
            ls[nds] = rs[nds] = -1;
            st[nds++] = neutral;
            return nds-1;
        }
        void build(int p, int l, int r, int* A) {
            if(l == r){
                st[p] = A ? A[l] : neutral;
                return;
            }
            int m = (l + r) / 2;
            build(ls[p] = newnode(), l, m, A);
            build(rs[p] = newnode(), m+1, r, A);
            st[p] = comp(st[ls[p]], st[rs[p]]);
        }
        void update(int prv, int p, int l, int r, int i, int k) {
            if(l == r){
                st[p] = st[prv] + k; //agrega
                return;
            }
            int m = (l + r) / 2;
            if(i <= m){
                rs[p] = rs[prv];
                update(ls[prv], ls[p] = newnode(), l, m, i, k);
            }
            else{
                ls[p] = ls[prv];
                update(rs[prv], rs[p] = newnode(), m+1, r, i, k);
            }
            st[p] = comp(st[ls[p]], st[rs[p]]);
        }
        int query(int p, int l, int r, int a, int b) {
            if (a > r || b < l) return neutral;
            if (l >= a && r <= b) return st[p];
            int m = (l + r) / 2;
            int p1 = query(ls[p], l, m, a, b);
            int p2 = query(rs[p], m + 1, r, a, b);
            return comp(p1, p2);
        }
    public:
        persistentSeg(int* begin, int* end){
            nds = nv = 0; size = (int)(end-begin);
            vroot[nv++] = newnode();
            build(vroot[0], 0, size-1, begin);
        }
        persistentSeg(int _size = 1){
            nds = nv = 0; size = _size;
            vroot[nv++] = newnode();
            build(vroot[0], 0, size-1, NULL);
        }
        int query(int a, int b, int v){
            return query(vroot[v], 0, size-1, a, b);
        }
        int update(int i, int v, int k){
            vroot[nv++] = newnode();
            update(vroot[v], vroot[nv-1], 0, size-1, i, k);
            return nv-1;
        }
        int nver() { return nv; }
        int sq(int i, int j, int l, int r, int k){
            if(l == r) return l;
            int mid = (l+r) >> 1;
            int all = st[ls[j]] - st[ls[i]];
            if(all >= k){
                return sq(ls[i], ls[j], l, mid, k);
            }
            return sq(rs[i], rs[j], mid + 1, r, k-all);
        }
        int sq(int i, int j, int k){
            return sq(vroot[i], vroot[j], 0, size - 1, k);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    map<int,int> cp, revcp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cp[a[i]];
    }
    int k = 0;
    for (auto &[u,v] : cp) {
        v = ++k;
        revcp[k] = u;
    }
    for (auto &u : a) {
        u = cp[u];
    }
    persistentSeg seg(k + 1);
    for (int i = 1; i <= n; i++) {
        seg.update(a[i], i - 1, 1);
    }
    vector<int> roots(n + 1);
    for (int i = 0; i <= n; i++) roots[i] = i;
    while (q--) {
        char o;
        cin >> o;
        if (o == 'Q') {
            int l,r,y;
            cin >> l >> r >> y;
            cout << revcp[seg.sq(roots[l-1], roots[r], y)] << '\n';
        }
        else {
            int x;
            cin >> x;
            roots[x] = seg.update(a[x], roots[x], -1);
            roots[x] = seg.update(a[x + 1], roots[x], 1);
            swap(a[x], a[x + 1]);
        }
    }
}





