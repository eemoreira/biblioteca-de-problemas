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
const int mod = 1e9 + 7, mx = 2e5 + 5;// 998244353
vi dp[mx];

void solve(){
  int n; cin >> n;
  vi a(n); 
  for(auto &u : a) cin >> u;
  vi b = a;
  map<int,int> who, rwho; 
  sor(b);
  int to = 0;
  for(int i = 0; i < n; i++){
    if(!who[b[i]]){
      who[b[i]] = ++to;
      rwho[to] = b[i];
    }
  }
  vector<vii> f(n+1);
  for(auto &u : a) u = who[u];
  a.pb(inf);
  for(int i = 0; i < n; i++){
    int it = i;
    while(a[i] == a[i+1]){
      i++;
    }
    f[a[i]].eb(it,i);
  }
  vi vis(n+1);
  int ma = 0;
  vi ans = {0,0,0};
  debug(a);
  for(int i = 0; i < n; i++){
    if(vis[a[i]])continue;
    debug(f[a[i]]);
    vis[a[i]] = 1;
    int fi = f[a[i]][0].fst, s = f[a[i]][0].snd;
    int cnt = s - fi + 1;
    if((int)f[a[i]].size() == 1){
      if(cnt > ma){
        ans = {rwho[a[i]],fi+1,s+1};
        ma = cnt;
      }
    }
    for(int j = 0; j < (int)f[a[i]].size()-1; j++){
      if(cnt > ma){
        ans = {rwho[a[i]],fi+1,s+1};
        ma = cnt;
      }
      ii cur = f[a[i]][j+1];
      cnt -= cur.fst - s - 1;
      if(cnt <= 0){
        fi = cur.fst;
        s = cur.snd;
        cnt = s - fi + 1;
      }
      else{
        cnt += cur.snd - cur.fst + 1;
        s = cur.snd;
      }
      if(cnt > ma){
        ans = {rwho[a[i]],fi+1,s+1};
        ma = cnt;
      }
    }
  }
  for(auto u : ans) cout << u << ' ';
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



