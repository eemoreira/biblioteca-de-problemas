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
const int mod = 998244353;
const int mx = 2e5 + 5;

vi adj[mx];
ll dp[mx], f[mx];
bool vis[mx];
int sz[mx];
int n; 

void dfs(int v){
  vis[v] = true;
  int cnt = 0;
  for(auto u : adj[v]){
    if(vis[u])continue;
    dfs(u);
    dp[v] = dp[v]%mod*dp[u]%mod;
    cnt++;
  }
  dp[v] = dp[v]%mod*f[cnt + (v != 0)]%mod;
  debug(n);debug(v);debug(dp[v]);
}

void solve(){
  cin >> n;
  for(int i = 1; i < n; i++){
    int u,v; cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
    dp[i] = 1;
  }
  dp[0] = 1;
  dfs(0);
  debarr(dp,n);
  debarr(f,n);
  cout << n*dp[0]%mod << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  f[0] = 1;
  for(int i = 1; i < mx; i++) f[i] = f[i-1]*i%mod;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



