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
const int mod = 1e9+7, mx = 2e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,m;
  cin >> n >> m;
  vector<vi> a(n, vi(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vi> c(n, vi(m));
  int l = 1, r = min(n,m) +1;
  int ans = 1;
  while(l <= r){
    int mid = (l+r)>>1;
    vector<vi> p(n+1, vi(m+1));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        c[i][j] = a[i][j] >= mid;
      }
    }
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        p[i][j] = p[i-1][j] + p[i][j-1] + c[i-1][j-1] - p[i-1][j-1];
      }
    }
    bool ok = false;
    /* debug(mid); */
    /* debug(p); */
    for(int i = 1; i <= n - mid + 1; i++){
      for(int j = 1; j <= m - mid + 1; j++){
        /* debug(i+mid-1, j+mid-1); */
        /* debug(i+mid-1, j-1); */
        /* debug(i-1, j+mid-1); */
        /* debug(i-1, j-1); */
        if(p[i+mid-1][j+mid-1] - p[i+mid-1][j-1] - p[i-1][j+mid-1] + p[i-1][j-1] >= (ll)mid*mid){
          ok = true;
        }
      }
    }
    if(ok){
      l = mid + 1;
      ans = mid;
    }
    else r = mid - 1;
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



