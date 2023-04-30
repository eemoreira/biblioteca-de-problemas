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
  int n;
  cin >> n;
  vll k(n), h(n);
  for(auto &u : k) cin >> u;
  for(auto &u : h) cin >> u;
  vll when(n);
  for(int i = 0; i < n; i++){
    when[i] = k[i] - h[i] + 1;
  }
  auto find = [&](int i){
    pair<ll,int> mi = mp(linf,inf);
    for(; i < n; i++){
      mi = min(mi, mp(when[i],i));
    }
    return mi;
  };
  debug(when);
  ll ans = 0;
  int ptr = 0;
  while(ptr < n){
    auto p = find(ptr);
    vi check;
    check.eb(p.snd);
    debug(p);
    for(int i = ptr; i < n; i++){
      bool ok = false;
      if(h[i] == 1) continue;
      for(int j = 0; j < (int)check.size(); j++){
        if(when[i] <= k[check[j]]){
          ok = true;
        }
      }
      if(ok){
        check.eb(i);
      }
    }
    debug(check);
    ll wh = p.fst;
    int id = check.back();
    ll s = (k[id] - wh + 1);
    debug(s);
    if(h[id] > 1){
      ans += s*(s+1)/2;
    }
    else{
      assert(id == p.snd);
      ans++;
    }
    ptr = check.back()+1;
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



