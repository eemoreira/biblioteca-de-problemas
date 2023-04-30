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
const int mod = 1e9+7, mx = 1e5 + 200;
vi primes;
int isp[mx];

void solve(){
  int n; cin >> n;
  vi a(n);
  for(auto &u : a){
    cin >> u;
  }
  sor(a);
  for(int i = 0; i < n-1; i++){
    if(a[i] <= 1)continue;
    if(a[i+1] == a[i]){
      cout << "yes\n";
      return;
    }
  }
  int p = 0;
  unordered_map<int,int> f;
  for(auto u : a) if(u*u >= a.back()) f[u]++;
  while(p < (int)primes.size() && primes[p]*primes[p] <= a.back()){
    int g = primes[p];
    int ans = 0;
    for(auto u : a){
      if(u <= 1)continue;
      bool ok = true;
      while(g*g <= a.back() && u%g==0){
        if(g < u) f[g]++;
        if(f[g] >= 2){
          cout << "yes\n";
          return;
        }
        g *= primes[p];
      }
    }
    p++;
  }
  cout << "no\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  for(int i = 2; i*i <= inf; i++) isp[i] = 1;
  isp[0] = isp[1] = 0;
  for(int i = 2; (ll)i*i <= inf; i++) {
    if(isp[i]){
      for(ll j = i*i; j*j <= inf; j += i)
        isp[j] = 0;
    }
  }
  for(int i = 2; i*i < inf; i++) if(isp[i]) primes.pb(i);
  /* cout << primes.size() << '\n'; */
  /* cout << primes.back()*primes.back() << '\n'; */
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}




