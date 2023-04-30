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

void solve(){
  ll n,p; cin >> n >> p;
  vll fac(n+1);
  fac[0] = 1;
  for(int i = 1; i <= n; i++){
    fac[i] = fac[i-1] * i % p;
  }
  auto InvMod = [&](ll v, int pp){
    ll ans = 1;
    pp-=2;
    while(pp){
      if(pp&1){
        ans = ans * v % p;
      }
      pp >>= 1;
      v = v*v % p; 
    }
    return ans;
  };
  vll f(n+1);
  for(int i = n/2; i < n; i++){
    ll up = fac[n - n/2 - 1];
    ll dw = fac[i - n/2]; 
    ll dwmup = fac[n - 1 - i]; 
    ll g = (dw * dwmup)%p;
    ll inv = InvMod(g,p);
    f[i] = (ll) (n%p * fac[i]%p * up%p * inv%p)%p;
  }
  f[n-1] = f[n] = fac[n];
  int ans = 0;
  for(int i = 0; i < n-1; i++){
    ans = (ans + f[i+1] - (n-i)*f[i])%p;
  }
  cout << (ans + p)%p << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



