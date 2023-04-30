#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mx = 2e5 + 5, mod = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u : a) cin >> u;
    int where[mx];
    for(int i = 0; i < n; i++){
        where[a[i]] = i;
    }
    ll ans = 1;
    int l,r;
    l = r = where[0];
    for(int i = 1; i < n; i++){
        if(where[i] < l) l = where[i];
        else if(where[i] > r) r = where[i];
        else ans = (ans%mod * (r - l + 1 - i))%mod;
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


