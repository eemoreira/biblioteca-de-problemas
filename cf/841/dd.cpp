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

const int LOG = 11;
const int N = 1010;
int p2[N];
vector<vector<int>> sparse[LOG];
vector<vi> a;
int n,m;

namespace sparse2d{
  void build(){ // sparse[0][i][j] = a[i][j]
    for(int k = 0; k < LOG ; k++){
      sparse[k] = vector<vi> (n, vi(m, inf));
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        sparse[0][i][j] = a[i][j];
      }
    }
    for(int k = 0; k < LOG - 1; k++){
      for(int i = 0; i + (1 << (k + 1)) <= n; i++){
        for(int j = 0; j + (1 << (k + 1)) <= m; j++){
          sparse[k + 1][i][j] = 
            min({sparse[k][i][j], sparse[k][i + (1 << k)][j], 
              sparse[k][i][j + (1 << k)], sparse[k][i + (1 << k)][j + (1 << k)]});
        }
      }
    }
  }
  int getMin(int x, int y, int d) {
    int k = p2[d];
    int s = d - (1 << k);
    return min({sparse[k][x][y], sparse[k][x + s][y], sparse[k][x][y + s], sparse[k][x + s][y + s]});
  }
}

bool check(int b){
  int ma = 0;
  for(int i = 0; i <= n - b; i++){
    for(int j = 0; j <= m - b; j++){
      ma = max(ma, sparse2d::getMin(i,j,b));
    }
  }
  return ma >= b;
}


void solve(){
  cin >> n >> m;
  a = vector<vi> (n, vi(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  sparse2d::build();
  int l = 1, r = min(n,m) + 1;
  int ans = 1;
  while(l <= r){
    int mid = (l+r) >> 1;
    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  for(int i = 2; i < N; i++){
    p2[i] = p2[i/2] + 1;
  }
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



