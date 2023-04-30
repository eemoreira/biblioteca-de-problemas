#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> pqmin;
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

#define int long long
struct fenwick{
  vll ft;
  fenwick(int n){
    ft.assign(n + 1,0); // 1 indexed
  }
  ll rsq(int i){
    ll sum = 0;
    for(; i; i -= (i & -i)){
      sum += ft[i];
    }
    return sum;
  }
  ll rsq(int i,int k){
    return rsq(k) - rsq(i-1);
  }
  void update(int i, int v){
    for(; i < (int) ft.size() ; i += (i & -i)){
      ft[i] += v;
    }
  }
};



void solve(){
  int n,m;
  cin >> n >> m;
  vll a(n);
  for(auto &u : a) cin >> u;
  ll ans = 0;
  ll all = 0;
  fenwick f(n);
  priority_queue<pair<ll,int>> pq;

  for(int i = 0; i < n; i++) f.update(i+1,a[i]);

  for(int i = m-2; i >= 0; i--){
    if(a[i+1] > 0) pq.emplace(a[i+1],i+1);
    while(!pq.empty() && f.rsq(1,i+1) < f.rsq(1,m)){
      debug(i);
      ans++;
      auto t = pq.top();
      pq.pop();
      f.update(t.snd+1, -2*t.fst);
    }
  }
  pqmin w;
  for(int i = m; i < n; i++){
    if(a[i] < 0) w.emplace(a[i],i);
    while(!w.empty() && f.rsq(1, i+1) < f.rsq(1,m)){
      auto t = w.top();
      w.pop();
      ans++;
      f.update(t.snd+1, -2*t.fst);
    }
  }
  cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



