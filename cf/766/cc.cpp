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
const int mod = 1e9+7, mx = 2e5 + 5;
vi adj[mx];
bool vis[mx];
bool ok = true;

void dfs(map<ii,int> &ans, int v,int p){
  vis[v] = true;
  int cnt = 0;
  for(auto u : adj[v]){
    if(vis[u])continue;
    cnt++;
    ok &= cnt <= 1;
    ans[ii(min(v,u),max(v,u))] = p;
    dfs(ans, u, p == 2 ? 3 : 2);
  }
}

void solve(){
  int n; cin >> n;
  ok = true;
  for(int i = 0; i < n; i++){
    adj[i].clear();
    vis[i] = false;
  }
  map<ii,int> ans;
  vii getans;
  for(int i = 1; i < n; i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
    if(u > v) swap(u,v);
    getans.eb(u,v);
  }
  int root = -1;
  for(int i = 0; i < n; i++){
    if(root==-1 && (int)adj[i].size() == 1) root = i;
  }
  debug(root);
  dfs(ans,root,2);
  if(!ok){
    cout << -1 << '\n';
    return;
  }
  for(auto u : getans) cout << ans[u] << ' ';
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



