#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

struct node {
  int id;
  long long mx;
  node(int i, long long m) {
    id = i;
    mx = m;
  }
};

node comp(node a, node b) {
  if (a.mx == b.mx) {
    return (a.id < b.id ? a : b);
  }
  return a.mx > b.mx ? a : b;
}
const node neutral = node(1e9,-1e9);

template<typename T>
class SegTree {
private:
  vector<T> tree;
  int n;
  int le(int i) { return 2*i;}
  int ri(int i) { return 2*i + 1;}
  void build(int v, int l, int r, vector<T> &a) {
    if (l == r) {
      tree[v] = node(l, 1e9);
      return;
    }
    int mid = (l+r)>>1;
    build(le(v), l, mid, a);
    build(ri(v), mid+1, r, a);
    tree[v] = comp(tree[le(v)], tree[ri(v)]);
  }
  void update(int v, int l, int r, int pos, T val) {
    if (l > pos || r < pos) return;
    if (l == r) {
      tree[v] = val;
      return;
    }
    int mid = (l+r)>>1;
    if (pos <= mid) {
      update(le(v), l, mid, pos, val);
    }
    else {
      update(ri(v), mid+1, r, pos, val);
    }
    tree[v] = comp(tree[le(v)], tree[ri(v)]);
  }
  T query (int v, int l, int r, int L, int R){
    if (l > R || r < L) return neutral;
    if (l >= L && r <= R) {
      return tree[v];
    }
    int mid = (l+r)>>1;
    return comp(query(le(v), l, mid, L, R), query(ri(v), mid+1, r, L, R));
  }
public:
  SegTree (vector<T> &v) {
    n = v.size();
    tree.assign(4*n,neutral);
    build(1,1,n,v);
  }
  void update (int pos, T val) {
    update(1,1,n,pos,val);
  }
  T query (int l, int r) {
    return query(1,1,n,l,r);
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<long long> ans(n);
  vector<node> trash(n, neutral);
  SegTree<node> seg(trash);
  for (int i = 0; i < n; i++) {
    node q = seg.query(1,a[i]);
    if (i > 0) {
      ans[i] = ans[i-1];
    }
    while (q.mx > a[i]) {
      seg.update(q.id, node(q.id, a[i]));
      dbg(q.id, q.mx, i, a[i]);
      if (q.mx == 1e9) {
        ans[i] += a[i] - q.id;
        break;
      }
      ans[i] += a[i] - q.id;
      ans[i] -= q.mx - q.id;
      a[i] = q.mx;
      q = seg.query(1,a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





