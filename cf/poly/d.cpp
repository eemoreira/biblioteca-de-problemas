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
typedef tuple<int,int,int> i3;

int ok2321 = 1;
//998244353
const int mod = 1e9+7, mx = 2e5 + 5;

void solve(){
  int n,m; cin >> n >> m;
  vector<vi> a(n, vi(m));
  ll check = 0;
  vii p(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      check += a[i][j];
      p[i].fst += a[i][j];
    }
    p[i].snd = i;
  }
  if(check%n){
    cout << -1 << '\n';
    return;
  }
  int need = check/n;
  sor(p);
  reverse(all(p));
  debug(need);
  vector<i3> ans;
  for(int i = 0; i < n; i++){
    if(p[i].fst <= need) break;
    int it = n-1;
    while(it > 0 && p[it].fst == need) it--;
    while(it > 0 && p[it].fst < need){
      for(int j = 0; j < m; j++){
        if(p[it].fst == need) break;
        if(p[i].fst == need) break;
        if(!a[p[it].snd][j] && a[p[i].snd][j]){
          ans.eb(p[i].snd+1,p[it].snd+1,j+1);
          swap(a[p[it].snd][j],a[p[i].snd][j]);
          p[it].fst++;
          p[i].fst--;
        }
      }
      if(p[i].fst == need) break;
      it--;
    }
  }
  cout << (int)ans.size() << '\n';
  for(auto [u,w,v] : ans) cout << u << ' ' << w << ' ' << v << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



