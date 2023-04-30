#include <bits/stdc++.h>

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll extgcd(int a, int b, ll& x, ll& y) {
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

pair<ll,ll> crt(vector<ll>& a, vector<ll>& m){
  if(a.size() != m.size()) return {-1,-1};
  int n = a.size();
  ll a0 = a[0];
  ll m0 = m[0];
  for(int i = 1; i < n; i++){
    ll p,q;
    extgcd(m0,m[i],p,q);
    ll md = m0*m[i];
    ll x = (a0%md*m[i]%md*q%md + a[i]%md*m0%md*p%md)%md;
    a0 = x;
    m0 = m0*m[i];
  }
  a0 += m0;
  a0 %= m0;
  return mp(a0,m0);
}

void solve(){
  auto ask = [&](ll a, ll b){
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
  };
  vector<ll> p = {2,3,5,7,11,13,17,19,23,29};
  ll lcm = 1;
  for(auto u : p) lcm *= u;
  int igr = 0;
  for(auto &u : p){
    if(lcm/u > 1e9 && lcm/u <= 2e9){
      lcm /= u;
      igr = u;
      break;
    }
  }
  int ps = p.size();
  vector<ll> a(ps-1);
  int y = 1e9;
  for(int i = 1; i <= 30; i++){
    int g = ask(i,i+lcm); // gcd(i+lcm+x, i+x) -> gcd(i+x, lcm)
    for(int j = 0; j < ps; j++){
      if(p[j] == igr) continue;
      if(g%p[j] == 0){
        int id = j - (p[j] > igr);
        a[id] = (p[j]-i)%p[j];
        if(a[id] < 0) a[id] += p[j];
      }
    }
  }
  vector<ll> actualp;
  for(auto u : p) if(u != igr) actualp.eb(u);
  cout << "! " << crt(a,actualp).fst << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



