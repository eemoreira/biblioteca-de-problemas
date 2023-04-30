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

#define comp(a,b) min(a,b)
const int neutral = 1e9;

template<typename T>
class segTree{
private:
  vector<T> tree;
  int n;
  int le(int i){ return 2*i;}
  int ri(int i){ return 2*i + 1;}
  void build(int v, int l, int r, vector<T> &a){
    if(l == r){
      tree[v] = a[l-1];
      return;
    }
    int mid = (l+r)>>1;
    build(le(v), l, mid, a);
    build(ri(v), mid+1, r, a);
    tree[v] = comp(tree[le(v)], tree[ri(v)]);
  }
  void update(int v, int l, int r, int pos, T val){
    if(l > pos || r < pos) return;
    if(l == r){
      tree[v] = val;
      return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){
      update(le(v), l, mid, pos, val);
    }
    else{
      update(ri(v), mid+1, r, pos, val);
    }
    tree[v] = comp(tree[le(v)], tree[ri(v)]);
  }
  T query(int v, int l, int r, int L, int R){
    if(l > R || r < L) return neutral;
    if(l >= L && r <= R){
      return tree[v];
    }
    int mid = (l+r)>>1;
    return comp(query(le(v), l, mid, L, R), query(ri(v), mid+1, r, L, R));
  }
public:
  segTree(vector<T> &v){
    n = v.size();
    tree.assign(4*n, neutral);
    build(1,1,n,v);
  }
  void update(int pos, T val){
    update(1,1,n,pos,val);
  }
  T query(int l, int r){
    return query(1,1,n,l,r);
  }
};

void solve(){
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  segTree<int> seg(a);
  set<int> ans;
  for(int i = 1; i <= n; i++){
    int m = seg.query(1,i);
    ans.emplace(m);
  }
  while (q--) {
    int i,v;
    cin >> i >> v;
    a[i-1] -= v;
    dbg(ans);
    int m = seg.query(1,i);
    auto r = ans.lower_bound(m);
    seg.update(i, a[i-1]);
    int now = seg.query(1,i);
    auto ptr = ans.lower_bound(now);
    while(ptr != r){
      ans.erase(ptr++);
    }
    /* dbg(ans, now, *ptr, m); */
    ans.emplace(now);
    if (seg.query(1,i) != m) {
      if (i == 1 || (i > 1 && seg.query(1,i-1) != m)) {
        ans.erase(m);
      }
    }
    cout << ans.size() << ' ';
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



