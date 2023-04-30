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
const int mod = 1e9+7, mx = 5e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define comp(a,b) min(a,b)
const ll neutral = linf;
class SegTree{
  vll a;
  int n;
  public:
  SegTree(ll* st, ll* end){
    int size = int(end-st);
    for(n = 1; n <= size; n <<= 1);
    a.assign((n << 1), neutral);
    for(int i = 0; i < size; i++) a[i+n] = st[i];
    for(int i = n + size; i > 1; i--){
      a[i>>1] = comp(a[i>>1],a[i]);
    }
  }
  void update(int i, int x){
    a[i+=n] = x; 
    for(i >>= 1; i; i >>= 1){
      a[i] = comp(a[i<<1],a[1 + (i<<1)]);
    }
  }
  ll query(int l, int r){
    ll ans = linf;
    for(l+=n, r+=n+1; l < r; l>>=1,r >>= 1){
      if(l&1) ans = comp(ans, a[l++]);
      if(r&1) ans = comp(ans, a[--r]);
    }
    return ans;
  }
};


void solve(){
  string x;
  int k;
  cin >> x >> k;
  int n = x.size();
  int id = 0;
  char mi = 'z';
  for(int i = 0; i <= k; i++){
    if(x[i] == '0')continue;
    if(x[i] < mi){
      mi = x[i];
      id = i;
    }
  }
  k -= id;
  string t = x;
  reverse(all(t));
  for(int i = 0; i < id; i++) t.pop_back();
  reverse(all(t));
  ll a[mx];
  for(int i = 0; i < n; i++) a[i] = t[i] - '0';
  SegTree seg(a,a+n);
  n = t.size();
  string ans = "";
  ans += t[0];
  for(int i = 1; i < n;){
    char nxt = '0' + seg.query(i,min(n-1,i+k));
    debug(nxt,k,i);
    int it = i;
    while(it < n && t[it] != nxt) it++;
    ans += nxt;
    k -= (it - i);
    i = it+1;
  }
  for(int i = 0; i < k; i++) ans.pop_back();
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



