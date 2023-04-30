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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vi primes;
bool isp[100];
const int totalp = 19;
int dp[75][1 << totalp], pos[75][2];

void solve(){
  int n;
  cin >> n;
  pos[0][0] = pos[0][1] = 0;
  for(int i = 1; i <= 70; i++) pos[i][0] = 1;
  for(int i = 0; i < n; i++){
    int u;
    cin >> u;
    int k = pos[u][0];
    pos[u][0] = (pos[u][0] + pos[u][1])%mod;
    pos[u][1] = (k + pos[u][1])%mod;
  }
  vi mask(75);
  for(int i = 1; i <= 70; i++){
    for(int j = 0; j < totalp; j++){
      int t = i;
      while(t%primes[j] == 0){
        mask[i] ^= 1 << j;
        t /= primes[j];
      }
    }
  }
  dp[0][0] = 1;
  for(int i = 1; i <= 70; i++){
    for(int msk = 0; msk < (1 << totalp); msk++){
      dp[i][msk] = (ll)dp[i-1][msk]*pos[i][0]%mod + (ll)dp[i-1][msk ^ mask[i]]*pos[i][1]%mod;
      dp[i][msk] %= mod;
    }
  }
  int ans = (dp[70][0]%mod + mod - 1)%mod;
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  for(int i = 2; i <= 70; i++) isp[i] = true;
  for(int i = 2; i <= 70; i++){
    if(!isp[i]) continue;
    primes.eb(i);
    for(int j = i*i; j <= 70; j+=i){
      isp[j] = false;
    }
  }
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



