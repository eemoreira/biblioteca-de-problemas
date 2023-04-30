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
const int mod = 998244353;

void solve(){
  int n,m; cin >> n >> m;
  vi a(n);
  for(auto &u : a) cin >> u;
  ll ans = 1;
  bool ok = true;
  for(int i = 1; i < n; i++){
    if(a[i-1]%a[i]){
      ok = false;
      break;
    }
    ll cur = a[i-1]/a[i];
    vi f;
    int d = 2;
    while(d*d <= a[i-1]/a[i] && cur > 1){
      if(cur%d==0){
        f.pb(d);
        while(cur%d==0) cur /= d;
      }
      d++;
    }
    if(cur > 1) f.pb(cur);
    ll dif = 0;
    for(int mask = 0; mask < (1 << (int)f.size()); mask++){
      int msk = mask;
      int it = 0;
      int c = 0;
      ll all = 1;
      while(msk){
        if(msk&1){
          all *= f[it];
          c++;
        }
        msk >>= 1;
        it++;
      }
      if(!c)continue;
      dif = dif + (c&1 ? 1 : -1)*m/(a[i]*all);
    }
    ans = ans*(m/a[i] - dif + mod)%mod;
  }
  if(!ok){
    cout << 0 << '\n';
    return;
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



