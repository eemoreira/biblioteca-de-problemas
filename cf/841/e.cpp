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
const int mod = 1e9+7, mx = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n,m;

ll mu[mx];

void solve(){
  cin >> n >> m;
  ll ans = 0;
  int f = 0;

  vll cnt(n+1);

  for(int i = 2; i <= n; i++){ // cnt[i] = coprimos de 1 ate n/i;
    for(int j = 1; j <= n/i; j++){
      cnt[i] += mu[j]*((n/i)/j)*((n/i)/j);
    }
    cnt[i] = (cnt[i]-1)/2;
  }

  for(ll i = n; i >= 2; i--){
    ll mi = min(cnt[i],m);
    ll dif = (i-1)*(mi/(i-1));
    m -= dif;
    ans += i*(mi/(i-1));
    if(m == 0) break;
  }
  if(m){
    cout << -1 << '\n';
  }
  else{
    cout << ans << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  mu[1] = 1;
  for(int i = 1; i < mx; i++){
    for(int j = 2 * i; j < mx; j += i){
      mu[j] -= mu[i];
    }
  }
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



