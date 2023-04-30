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

#define int long long

ll solve(vll a, int n, ll ma){
  if(ma == 0) return inf;
  debug(a,n,ma);
  ll odd = 0;
  while(!a.empty() && a.back() == ma) a.pop_back();
  n = a.size();
  for(int i = 0; i < n; i++){
    if((ma&1) != (a[i]&1)){
      odd++;
      a[i]++;
    }
  }
  ll ans = 0;
  if(odd){
    ans = 1 + 2*(odd-1);
  }
  while(!a.empty() && a.back() == ma){
    a.pop_back();
  }
  n = a.size();
  debug(a);
  debug(ans,odd);
  sor(a);
  sor(a);
  debug(a);
  ll all = 0;
  for(auto u : a) all += ma-u;
  if(odd){
    all -= 2*(odd-1);
  }
  debug(all,ans);
  ll l = 0, r = all;
  ll t = 0;
  while(l <= r){
    ll mid = (l+r)>>1;
    if(odd){
      if(2*((mid+1)/2) + mid/2 >= all){
        r = mid - 1;
        t = mid;
      }
      else{
        l = mid + 1;
      }
    }
    else{
      if((mid+1)/2 + 2*(mid/2) >= all){
        r = mid - 1;
        t = mid;
      }
      else{
        l = mid + 1;
      }
    }
  }
  debug(t);
  return ans + t;
}

// 2*(x+1)/2 + mid/2

void solve(){
  int n;
  cin >> n;
  vll a(n);
  for(auto &u : a) cin >> u;
  ll maodd = 0, maev = 0;
  for(int i = 0; i < n; i++){
    if(a[i]&1){
      maodd = max(maodd, a[i]);
    }
    else{
      maev = max(maev, a[i]);
    }
  }
  sor(a);
  if(maev > maodd) maodd = maev+1;
  else maev = maodd+1;
  cout << min(solve(a,n,maodd), solve(a,n,maev)) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


