const int neutral = 0; //comp(x, neutral) 
#define MAXS 2000009
#define MAXN 200009
#define comp(a, b) ((a)+(b))

int nds, st[MAXS], ls[MAXS], rs[MAXS];

class persistentSeg {
    private:
        int vroot[MAXN];
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
            return sq(rs[i], rs[j], mid+1, r, k-all);
        }
        int sq(int i, int j, int l, int r, int k, int wtf){
            return sq(i <  0 ? wtf : vroot[i-1], vroot[j], l, r, k);
        }
};
