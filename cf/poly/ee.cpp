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

int ok2321 = 0;
//998244353
const int mod = 1e9+7, mx = 2e5 + 5;
vi adj[mx];

namespace st{
  int n, me;
  vector<vi> up;
  void bl_dfs(int u, int p) {
    up[u][0] = p;
    for(int i = 1; i <= me; i++){
      up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : adj[u]){
      if(v != p){
        bl_dfs(v, u);
      }
    }
  }
  void build(int _n, int root){
    n = _n;
    me = floor(log2(n));
    up.assign(n, vi(me+1, 0));
    bl_dfs(root, root);
  }
  int ancestor(int v, int k){ // k-th ancestor of u 
    for(int i = me; i >= 0; i--){
      if((1 << i) & k){
        v = up[v][i];
      }
    }
    return v;
  }
}

int ddad[mx];
int a[2][mx];

void dfs(int v, int p){
  for(int i = 0; i < 2; i++){
    a[i^1][ddad[v]] |= a[i][v];
  }
  for(auto u : adj[v]){
    if(u == p) continue;
    dfs(u,v);
  }
  for(int i = 0; i < 2; i++){
    a[i][p] |= a[i][v];
  }
}

void solve(){
  int n,d;
  cin >> n >> d;
  for(int i = 1; i < n; i++){
    int u,v;
    cin >> u >> v;
    --u;--v;
    adj[u].eb(v);
    adj[v].eb(u);
  }
  st::build(n,0);
  for(int i = 0 ; i < 2; i++){
    int q; 
    cin >> q;
    for(int j = 0; j < q; j++){
      int v;
      cin >> v;
      --v;
      a[i][v] = 1;
    }
  }
  for(int i = 0; i < n; i++) ddad[i] = st::ancestor(i,d);
  a[0][0] = a[1][0] = 1;
  dfs(0,0);
  ll ans = 0;
  for(int i = 0; i < 2; i++){
    for(int j = 1; j < n; j++){
      ans += 2*a[i][j];
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



