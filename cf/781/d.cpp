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

int ok2321 = 1;
//998244353
const int mod = 1e9+7, mx = 2e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 00001101
// 00000101#
#define int long long

void solve(){
  auto ask = [&](int a, int b){
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
  };
  int x = 0;
  int t = 1<<30;
  int y = 1<<29;
  for(int i = 1; i <= 30; i++){
    int b = 1ll<<i;
    if((x | b/2) > 1e9) break;
    if(i == 30){
      t -= 1<<30;
      t += 1<<29;
    }
    /* int ans = gcd(t+y,t+b+y); */
    int ans = ask(t,t+b);
    if(i == 30){
      if(ans == b){
        x |= b/2;
        t -= b/2;
      }
    }
    else if(ans != b){
      x |= b/2;
      t -= b/2;
    }
  }
  cout << "! " << x << '\n';
}

signed main(){
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}




