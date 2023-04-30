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
//998244353
const int mod = 1e9+7, mx = 2e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vll nxtma(vll a, int n){
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

void solve(){
  int n;
  cin >> n;
  vll a(n), b(n);
  for(auto &u : a) cin >> u;
  for(auto &u : b) cin >> u;
  int m;
  cin >> m;
  vll r(m);
  for(auto &u : r) cin >> u;
  sort(all(r));
  map<int,vi> f;
  for(int i = 0; i < n; i++){
    f[b[i]].eb(i);
  }
  map<int,int> cnt;
  vll nma = nxtma(b,n);
  map<int,int> used;
  for(int i = 0; i < n; i++){
    int c = 0;
    if(used[b[i]])continue;
    used[b[i]] = 1;
    for(int ptr = 0; ptr < (int)f[b[i]].size(); ptr++){
      bool ok = false;
      int y = ptr;
      if(ptr == (int)f[b[i]].size()-1){
        if(b[f[b[i]][ptr]] != a[f[b[i]][ptr]]){
          cnt[b[i]]++;
        }
        break;
      }
      while(ptr < (int)f[b[i]].size()-1 && nma[f[b[i]][ptr]] >= f[b[i]][ptr+1]){
        ptr++;
      }
      while(y <= ptr){
        ok |= a[f[b[i]][y]] != b[f[b[i]][y]];
        y++;
      }
      if(ok){
        cnt[b[i]]++;
      }
      else{
        if(a[f[b[i]][ptr]] != b[f[b[i]][ptr]]){
          cnt[b[i]]++;
        }
      }
    }
  }
  map<int,int> have;
  for(auto u : r) have[u]++;
  for(int i = 0; i < n; i++){
    if(a[i] < b[i]){
      cout << "no\n";
      return;
    }
    if(have[b[i]] < cnt[b[i]]){
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
}

// 1 1 4 3 5 3 4 5

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



