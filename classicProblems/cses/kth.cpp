#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5
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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#ifndef ONLINE_JUDGE
#define debarr(arr, n) cerr << "arr: ["; for(int i = 0; i < n; i++)  cerr << arr[i] << (i == n-1 ? "" : ", "); cerr << "]" << endl;
#else
#define debarr(x...)
#endif

#define MAXS 2000009
#define MAXN 200009

/*
 * Persistent Segment Tree
 */

const int neutral = 0; //comp(x, neutral) = x
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

int t[MAXN];

void solve(){
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> t[i];
  vii a(n);
  for(int i = 0; i < n; i++) a[i] = mp(t[i],i);
  sort(all(a));

  int m = 0;
  vi gt(n);
  for(int i = 0; i < n;){
    int it = i;
    while(i < n && a[i].fst == a[it].fst) i++;
    for(int j = it; j < i; j++){
      gt[m] = t[a[j].snd];
      t[a[j].snd] = m;
    }
    m++;
  }
  persistentSeg seg(n+1);
  for(int i = 0; i < n; i++){
    seg.update(t[i], seg.nver()-1, 1);
  }
  while(q--){
    int i,j,k;
    cin >> i >> j >> k;
    /* --i;--j; */
    cout << gt[seg.sq(i,j,0,m,k,-1)] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  while(tc--) solve();
  return 0;
}



