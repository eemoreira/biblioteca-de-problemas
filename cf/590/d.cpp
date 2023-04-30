#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */


#define comp(a,b) (a | b)
const int neutral = 0;

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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1 << (s[i] - 'a');
    }
    SegTree<int> seg(a);
    int q;
    cin >> q;
    dbg(a);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            char c;
            int pos;
            cin >> pos >> c;
            int i = c - 'a';
            seg.update(pos, (1 << i));
        }
        else {
            int l,r;
            cin >> l >> r;
            int qr = seg.query(l,r);
            cout << __builtin_popcount(qr) << '\n';
        }
    }
}





