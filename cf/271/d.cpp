#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
template<typename T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
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
/* const int mod = 998244353, mx = 2e5 + 5; */
const int mod = 1e9+7, mx = 2e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll a, ll b, ll m = mod){
  ll ans = (a%m + b%m + m)%m;
  if(ans < 0) ans += m;
  return ans;
}
ll mul(ll a, ll b, ll m = mod){
  ll ans = (a%m * b%m)%m;
  if(ans < 0) ans += m;
  return ans;
}
ll bpw(ll a, ll e, ll m = mod){
  ll ans = 1;
  while(e){
    if(e&1){
      ans = mul(ans,a,m);
    }
    a = mul(a,a,m);
    e >>= 1;
  }
  return ans;
}
ll invMod(ll a, ll m = mod){
  return bpw(a, m-2, m)%m;
}
ll dv(ll a, ll b, ll m = mod){
  return mul(a, invMod(b,m), m);
}

long long p[mx], dp[mx];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt,k;
  cin >> tt >> k;
  dp[0] = 1;
  for(int i = 1; i < mx; i++){
    dp[i] = dp[i-1];
    if(i >= k){
      dp[i] = add(dp[i], dp[i-k]);
    }
  }
  for(int i = 1; i < mx; i++){
    p[i] = p[i-1];
    p[i] = add(p[i],dp[i]);
  }
  while(tt--){
    int l,r;
    cin >> l >> r;
    cout << add(p[r],-p[l-1]) << '\n';
  }
}



