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

int mylb(vi &a, int x, int y, bool op = false){
  int n = a.size()-1;
  int l = x, r = n;
  int ans = 0;
  while(l<=r){
    int mid = (l+r)>>1;
    if(op){
      if(a[n] - a[mid] <= y){
        ans = mid+1;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    else{
      if(a[mid] <= y){
        ans = mid;
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }
  }
  if(!op){
    ans = lower_bound(all(a), a[ans]) - a.begin();
  }
  return ans;
}

void solve(){
  int n;
  cin >> n;
  vi a(n);
  for(auto &u : a) cin >> u;
  sort(a.begin(), a.end());
  if(n==1){
    cout << 2 << '\n';
    return;
  }
  vi pw;
  int t = 1;
  while(t <= n){
    pw.emplace_back(t);
    t <<= 1;
  }
  vi ind(n+1);
  for(int i = 0; i < n; i++){
    ind[a[i]] = i;
  }
  map<int,int> f;
  for(auto u : a) f[u]++;
  vi p(n+1);
  for(int i = 1; i <= n; i++){
    p[i] = p[i-1] + f[i];
  }
  debug(p);
  auto nxt2 = [&] (int x){
    int g = 1;
    if(x && x == (x&-x)) return x;
    while(g < x) g <<= 1;
    return g;
  };
  int ans = inf;
  for(auto u : pw){
    int x = mylb(p,0,u,false);
    for(auto y : pw){
      int g = mylb(p,x,y,true);
      int mid = max(0,p[g-1] - p[x]);
      ans = min(ans, nxt2(p[x]) - p[x] + nxt2(p[n]-p[g-1]) - p[n] + p[g-1] + nxt2(mid) - mid);
    }
  }
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



