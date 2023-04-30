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
const int mod = 998244353, mx = 2e5 + 5;

void solve(){
  int n,s; cin >> n >> s;
  vi a(n), b(n);
  for(auto &u : a) cin >> u;
  for(auto &u : b) cin >> u;
  vi m;
  vi have(n+1);
  vi check(n+1);
  int ma = -inf;
  for(int i = 0; i < n; i++){
    check[a[i]] = b[i];
    if(b[i] == -1)continue;
    ma = max(ma, a[i]-b[i]);
    have[b[i]] = 1;
  }
  for(int i = 1; i <= n; i++) if(!have[i]) m.pb(i);
  if(ma > s){
    cout << 0 << '\n';
    return;
  }
  vll ans;
  for(int i = 0; i < n; i++){
    if(check[a[i]] != -1) continue;
    int l = 0, r = (int)m.size()-1;
    int cur = 0;
    bool ok = false;
    while(l <= r){
      int mid = (l+r)>>1;
      if(m[mid] >= a[i] - s){
        ok = true;
        cur = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    if(ok)cur = (int)m.size() - cur;
    debug(cur);
    ans.pb(cur);
  }
  int cnt = 0;
  ll anss = 1;
  sor(ans);
  debug(ans);
  for(auto u : ans){
    ll cur = max(0ll, u - cnt);
    cnt++;
    anss = anss*cur%mod;
  }
  cout << anss << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}
