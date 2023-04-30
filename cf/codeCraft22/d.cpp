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

class SegmentTreeMax{
  vll a;
  int n;
  public:
  SegmentTreeMax(ll* st, ll* end){
    int size = int(end-st);
    for(n = 1; n <= size; n <<= 1);
    a.assign((n << 1), -linf);
    for(int i = 0; i < size; i++) a[i+n] = st[i];
    for(int i = n + size; i > 1; i--){
      a[i>>1] = max(a[i>>1],a[i]);
    }
  }
  ll query(int l, int r){
    ll ans = -linf;
    for(l+=n, r+=n+1; l < r; l>>=1,r >>= 1){
      if(l&1) ans = max(ans, a[l++]);
      if(r&1) ans = max(ans, a[--r]);
    }
    return ans;
  }
};

vll nxtma(ll* a, int n){
  vll stk;
  vll ans(n,n);
  for(int i = 0; i < n; i++){
    while((int)stk.size() && a[stk.back()] < a[i]){
      ans[stk.back()] = i;
      stk.pop_back();
    }
    stk.pb(i);
  }
  return ans;
}

ll a[mx];

bool check(int n){
  vll nma;
  nma = nxtma(a,n);
  ll p[mx];
  for(int i = 0; i <= n; i++) p[i] = 0;
  p[0] = a[0];
  for(int i = 1; i < n; i++){
    p[i] = p[i-1] + a[i];
  }

  SegmentTreeMax segpf(p,p+n);
  for(int i = 0; i < n; i++){
    if(segpf.query(i,nma[i]-1) - p[i] > 0){
      return false;
    }
  }
  return true;
}

void solve(){
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  if(!check(n)){
    cout << "no\n";
    return;
  }
  reverse(a,a+n);
  if(!check(n)){
    cout << "no\n";
    return;
  }
  cout << "yes\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



