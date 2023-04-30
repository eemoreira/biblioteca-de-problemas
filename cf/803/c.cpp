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
const int mod = 1e9 + 7; // 998244353

void solve(){
  int n; cin >> n;
  vll a(n);
  for(auto &u : a) cin >> u;
  ll sum = 0;
  ll nz = 0;
  if(!a[0] || !a[1] || !a[2]){
    for(auto u : a) nz += (u != 0);
    if(nz > 2){
      cout << "no\n";
      return;
    }
    nz = 0;
    for(auto u : a) if(u){
      nz += u;
    }
    debug(nz);
    for(auto u : a){
      if(u == nz){
        cout << "yes\n";
        return;
      }
    }
    cout << "no\n";
  }
  else{
    if(n > 4){
      cout << "no\n";
      return;
    }
    sum = a[0] + a[1] + a[2];
    bool ok = false;
    debug(sum);
    for(int i = 0; i < 3; i++) ok |= sum == a[i];
    if(!ok) cout << "no\n";
    else{
      map<ll,ll> have;
      for(auto u : a) have[u]++;
      if(n == 3) cout << "yes\n";
      else{
        for(int i = 0; i < 4; i++){
          for(int j = i+1; j < 4; j++){
            for(int l = j+1; l < 4; l++){
              if(!have[a[i]+a[j]+a[l]]){
                cout << "no\n";
                return;
              }
            }
          }
        }
        cout << "yes\n";
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



