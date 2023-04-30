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

int ok2321 = 0;
const int mod = 1e9 + 7, mx = 5e5 + 5; // 998244353
ll f[mx];

void solve(){
  int n; cin >> n;
  vll a(n+1);
  for(auto &u : a) cin >> u;
  ll ans = 0;
  auto GetInv = [&](ll aa){
    ll e = mod - 2;
    ll anss = 1;
    while(e){
      if(e&1){
        anss = (anss*aa)%mod;
      }
      aa = aa*aa%mod;
      e >>= 1;
    }
    return anss;
  };
  for(int i = 0; i < n+1; i++){
    if(a[i]==0)continue;
    ans += (f[a[i] + i]%mod * GetInv(f[i+1])%mod * GetInv(f[a[i] - 1])%mod)%mod;
  }
  cout << (ans+mod)%mod << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  f[0] = 1;
  for(int i = 1; i < mx; i++){
    f[i] = f[i-1]*i%mod;
  }
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



