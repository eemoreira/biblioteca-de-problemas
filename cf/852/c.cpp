#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

struct node {
  int mn;
  int mx;
  node(int m, int n) {
    mn = m;
    mx = n;
  }
};
const node neutral = node(1e9,-1e9);
node comp(node a, node b) {
  return node(min(a.mn,b.mn), max(a.mx,b.mx));
}

template<typename T>
class SegTree {
private:
  vector<T> tree;
  int n;
  int le(int i) { return 2*i;}
  int ri(int i) { return 2*i + 1;}
  void build(int v, int l, int r, vector<T> &a) {
    if (l == r) {
      tree[v] = a[l-1];
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
    tree.assign(4*n, neutral);
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
  vector<node> a(n,neutral);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i] = node(v,v);
  }
  SegTree<node> seg(a);
  int l = 0;
  int r = n-1;
  while (l < r) {
    node q = seg.query(l+1,r+1);
    if (q.mn == a[l].mx || q.mx == a[l].mx) {
      l++;
    }
    else if (q.mx == a[r].mx || q.mn == a[r].mx) {
      r--;
    }
    else {
      cout << l+1 << ' ' << r+1 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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






