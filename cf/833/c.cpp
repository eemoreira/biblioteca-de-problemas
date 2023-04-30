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

void solve(){
    int n; cin >> n;
    vll a(n);
    for(auto &u : a) cin >> u;
    vll p(n+1);
    bool ok = false;
    for(int i = 1; i <= n; i++) p[i] = p[i-1] + a[i-1];
    map<ll,ll> f;
    ll ma = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(ok) ans += ma;
            else ans += f[0];

            ok = true;
            ma = 0;
            f.clear();
        }
        ma = max(ma,++f[p[i+1]]);
    }
    if(ok) ans += ma;
    else ans += f[0];
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


