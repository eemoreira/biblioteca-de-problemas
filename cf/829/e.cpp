#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u: a) cin >> u;
    int o = 0, z = 0;
    for(auto u : a)  z += !u;
    for(int i = 0; i < z; i++) o += a[i];
    int ans = 0;
    ll p = ((ll)n*(n-1))/2 % mod;
    for(int i = 0; i < o; i++){
        ll invmod = 1;
        ll e = mod-2;
        ll b = (i+1);
        while(e){
            if(e&1){
                invmod = invmod*b%mod;
            }
            e >>= 1;
            b = b*b%mod;
        }
        ans = (ans + p*invmod%mod*invmod%mod)%mod;
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



