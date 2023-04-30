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

int ok2321 = 0;
//998244353
const int mod = 1e9+7, mx = 2e5 + 5;


void solve(){
  int n; cin >> n;
  vector<vi> d(n+1, vi(n+1));
  auto Ask2 = [&](int l, int r){
    if(l <= 0 || l > n || r <= 0 || r > n) return (int)inf;
    if(d[l][r]) return d[l][r];
    if(l == r) return d[l][r] = 1;
    cout << "? 2 " << l << ' ' << r << endl;
    fflush(stdout);
    int u; cin >> u;
    return d[l][r] = u;
  };
  auto Ask1 = [&](int u){
    cout << "? 1 " << u << endl;
    fflush(stdout);
    char c; cin >> c;
    return c;
  };
  string ans = "";
  vector<vi> cnt(n+1);
  ans += Ask1(1);
  cnt[0].pb(1);
  for(int i = 1; i < n; i++){
    if(Ask2(1,i+1) > cnt[i-1][0]){
      ans += Ask1(i+1);
    }
    else{
      map<int,int> last;
      for(int j = 0; j < (int)ans.size(); j++) last[ans[j]] = j;
      vi b;
      for(auto u : last) b.pb(u.snd);
      sor(b);
      int l = 0, r = (int)b.size()-1;
      int c = 0;
      while(l<=r){
        int mid = (l+r)>>1;
        if(Ask2(b[mid]+1,i+1) == cnt[i-1][b[mid]]){
          c = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }
      ans += ans[b[c]];
    }
    set<char> q;
    cnt[i].resize(i+1);
    for(int j = i; j >= 0; j--){
      q.insert(ans[j]);
      cnt[i][j] = q.size();
    }
  }
  cout << "! " << ans << endl;
}

int main(){
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



