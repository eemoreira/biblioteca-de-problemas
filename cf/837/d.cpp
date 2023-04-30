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

int ok2321 = 1;
//998244353
const int mod = 1e9+7, mx = 2e3 + 5;
vi adj[mx];
bool vis[mx];
int n;
string s;
int go[mx][mx];
vii pathlen[mx];

void dfs(int root, int v, int l, int x){
  vis[v] = true;
  if(l == 1){
    x = v;
  }
  if(l >= 1){
    go[root][v] = x;
  }
  pathlen[l].eb(root,v);
  for(auto u : adj[v]){
    if(vis[u])continue;
    dfs(root,u,l+1,x);
  }
}

void solve(){
  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++){
    adj[i].clear();
    vis[i] = false;
    pathlen[i].clear();
    for(int j = 0; j < n; j++){
      go[i][j] = 0;
    }
  }
  for(int i = 1; i < n; i++){
    int u,v;
    cin >> u >> v;
    --u;--v;
    adj[v].pb(u);
    adj[u].pb(v);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) vis[j] = false;
    go[i][i] = i;
    dfs(i,i,0,-1);
  }

  vector<vi> dp(n+1, vi(n+1));
  int ans = -inf;
  for(int l = 0; l <= n; l++){
    for(auto [v,u] : pathlen[l]){
      if(l == 0) dp[v][u] = 1;
      else{
        dp[v][u] = max(dp[go[v][u]][u], dp[v][go[u][v]]);
        if(s[v] == s[u]){
          dp[v][u] = max(dp[v][u], dp[go[v][u]][go[u][v]] + 2 - (go[u][v] == v));
        }
      }
      ans = max(ans,dp[v][u]);
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



