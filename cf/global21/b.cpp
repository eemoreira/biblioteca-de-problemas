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

int ok2321 = 1;
const int mod = 1e9 + 7; // 998244353

void solve(){
  int n; cin >> n;
  vi a(n);
  for(auto &u : a) cin >> u;
  ll ans = 0;
  bool ok = true;
  bool db = true;
  for(auto u : a) db &= (!u);
  int it = 0;
  while(a[it]==0){
    it++;
    if(it == n) break;
  }
  int itt = n-1;
  while(a[itt]==0){
    itt--;
    if(itt < 0) break;
  }
  for(int i = it; i < itt; i++) ok &= (a[i] != 0);
  if(db) cout << 0 << '\n';
  else if(ok) cout << 1 << '\n';
  else cout << 2 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



