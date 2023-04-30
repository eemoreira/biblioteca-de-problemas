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
const int mod = 1e9 + 7;

void solve(){
  int n,q; cin >> n >> q;
  if(q >= n){
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = ans*2%mod;
    cout << (ans+mod)%mod << '\n';
    return;
  }
  auto Inv = [&](ll a){
    int e = mod - 2;
    ll ans = 1;
    while(e){
      if(e&1){
        ans = ans * a %mod;
      }
      a = a * a % mod;
      e >>= 1;
    }
    return ans;
  };
  vll f(n+1), invf(n+1);
  f[0] = 1;
  invf[0] = 1;
  for(int i = 1; i <= n; i++){
    f[i] = f[i-1]*i%mod;
    invf[i] = Inv(f[i]);
  }
  ll ans = 0;
  for(int i = 0; i <= q; i++) ans = (ans + f[n]%mod * invf[i]%mod * invf[n-i]%mod)%mod;
  cout << (ans+mod)%mod << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



