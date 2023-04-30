#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

struct node {
  int mn;
  int gcd;
  node(int a, int b) {
    mn = a;
    gcd = b;
  }
};

const node neutral = node((int)1e9,0);
node merge(node a, node b) {
  return node(min(a.mn,b.mn), __gcd(a.gcd,b.gcd));
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
    tree[v] = merge(tree[le(v)], tree[ri(v)]);
  }
  T query (int v, int l, int r, int L, int R){
    if (l > R || r < L) return neutral;
    if (l >= L && r <= R) {
      return tree[v];
    }
    int mid = (l+r)>>1;
    return merge(query(le(v), l, mid, L, R), query(ri(v), mid+1, r, L, R));
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
  int n;
  cin >> n;
  vector<node> a(n, neutral);
  map<int,vector<int>> f;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i] = node(v,v);
    f[v].emplace_back(i+1);
  }
  SegTree<node> seg(a);
  int q;
  cin >> q;
  while (q--) {
    int l,r;
    cin >> l >> r;
    node sq = seg.query(l,r);
    int rg = r - l + 1;
    if (sq.mn == sq.gcd) {
      int lb = lower_bound(f[sq.mn].begin(), f[sq.mn].end(), l) - f[sq.mn].begin();
      int up = upper_bound(f[sq.mn].begin(), f[sq.mn].end(), r) - f[sq.mn].begin();
      rg -= (up - lb);
    }
    cout << rg << '\n';
  }
}




