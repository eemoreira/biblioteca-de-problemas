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

void solve(){
  ll n,x,y;
  cin >> n >> x >> y;
  vll a(n);
  for(auto &u : a) cin >> u;
  sort(all(a));
  int mr = 0;
  int id = -1;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(x+mr < a[i]) break;
    id = i;
    mr++;
    if(x+mr == y){
      cout << mr << '\n';
      return;
    }
  }
  if(id + 1 <= (n - id - 1) || id == -1){
    cout << -1 << '\n';
    return;
  }
  debug(id);
  debug(a);
  int h = id+1;
  while(x < y){
    ll am = 2*h - n;
    debug(x, h, am);
    if(h == n){
      ans += (y-x);
      x += (y-x);
      continue;
    }
    if(y <= a[h]){
      ll nd = y-h;
      debug(nd, (nd-x+am-1)/am);
      ans += n*((nd-x+am-1)/am);
      x += am*((nd-x+am-1)/am);
      ans += (y-x);
      x += (y-x);
    }
    else{
      ll nd = a[h]-h;
      debug(nd, (nd-x+am-1)/am);
      ans += n*((nd-x+am-1)/am);
      x += am*((nd-x+am-1)/am);
    }
    h++;
  }
  assert(x == y);
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



