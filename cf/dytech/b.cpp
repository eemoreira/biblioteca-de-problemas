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

void solve(){
  ll l,r; cin >> l >> r;
  auto Bs = [&] (ll a){
    ll ans = 0;
    for(int i = 0; i <= 2; i++){
      ll anss = 0;
      ll lt = 0, rt = 2e9;
      while(lt <= rt){
        ll mid = (lt+rt)>>1;
        if(mid*(mid+i) <= a){
          anss = mid;
          lt = mid + 1;
        }
        else rt = mid - 1;
      }
      ans += anss;
    }
    return ans;
  };
  cout << Bs(r) - Bs(l-1) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



