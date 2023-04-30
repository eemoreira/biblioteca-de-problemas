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
const int mod = 998244353, mx = 105;
ll dp[mx][mx][mx];


void solve(){
  int n; cin >> n;
  vector<vi> a(n+1, vi(n+1));
  vi last(n+1);
  for(int i = 1 ; i <= n; i++){
    for(int j = i; j <= n; j++){
      cin >> a[i][j];
    }
  }
  debug(a);
  dp[0][0][0] = 1;
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j <= i; j++){
      for(int k = 0; k <= i; k++){
        if(dp[i][j][k] == 0) continue;
        bool o,z;
        o = z = true;
        for(int l = 1; l <= i+1; l++){
          if(a[l][i+1] == 1){
            if(k >= l){
              o = false;
            }
            if(j >= l){
              z = false;
            }
          }
          if(a[l][i+1] == 2){
            if(k < l){
              o = false;
            }
            if(j < l){
              z = false;
            }
          }
        }
        if(o){
          dp[i+1][i+1][k] = dp[i+1][i+1][k]%mod + dp[i][j][k]%mod;
        }
        if(z){
          dp[i+1][j][i+1] = dp[i+1][j][i+1]%mod + dp[i][j][k]%mod;
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      debug(n,i,j,dp[n][i][j]);
      ans += dp[n][i][j]%mod;
    }
  }
  cout << ans%mod << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



