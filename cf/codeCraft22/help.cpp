struct segTree{
  ll n, tree[4*mx];

  int le(int i) { return 2*i+1; }
  int ri(int i) { return 2*i+2; }

  void build(int x, int esq, int dir, vector<long long> &v) {
    if(esq == dir) tree[x] = v[esq];
    else{
      int mid = (esq + dir) / 2;
      build(le(x), esq, mid, v);
      build(ri(x), mid+1, dir, v);
      tree[x] = tree[le(x)] + tree[ri(x)];
    }
  }
  void build(vector<long long> &v) { build(0, 0, n-1, v); }

  int query(int x, int esq, int dir, int l, int r) {
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[x];
    int mid = (esq + dir) / 2;
    return query(le(x), esq, mid, l, r)
      + query(ri(x), mid+1, dir, l, r);
  }
  int query(int l, int r) { return query(0, 0, n-1, l, r); }

  void update(int i, int esq, int dir, int x, int v) {
    if (esq > x || dir < x) return;
    if (esq == dir) tree[i] = v;
    else{
      int mid = (esq + dir) / 2;
      if (x <= mid) update(le(i), esq, mid, x, v);
      else update(ri(i), mid+1, dir, x, v);
      tree[i] = tree[le(i)] + tree[ri(i)];
    }
  }
  void update(int x, int v) { update(0, 0, n-1, x, v); }
};
