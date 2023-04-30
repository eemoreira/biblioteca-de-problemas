#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

int ok2321 = 0;
const int mx = 3e5 + 5;

ll primes[mx];


const ll mod = 998244353;

void solve(){
    ll n,m; cin >> n >> m;
    vector<ll> ppr(n+1);
    ppr[1] = 1; 
    for(ll i = 2; i <= n; i++){
        if(primes[i]){
            if(ppr[i-1] * i > m) ppr[i] = m +1;
            else ppr[i] = (ppr[i-1] * i);
        }
        else ppr[i] = ppr[i-1];
        /* cout << "i: " << i << ' ' << ppr[i] << endl; */
    }
    vector<ll> ans(n+1);
    ll all = 0;
    ll aa = m%mod;
    ll b = aa;
    for(int i = 1; i <= n; i++){
        /* cout << aa << endl; */
        all = (all + aa)%mod;
        aa = (aa*b)%mod;
    }
    /* cout << all << endl; */
    ans[1] = m%mod;
    for(int i = 2; i <= n; i++){
        ans[i] = ((ans[i-1]) * ((m/ppr[i])%mod))%mod;
        /* cout << "ans: " << ans[i] << endl; */
    }
    ll anss = 0;
    for(int i = 1; i <= n; i++) anss =  (anss+ ans[i])%mod;
    /* cout << all << ' ' << anss << endl; */
    cout << (all - anss + mod)%mod << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    for(int i = 2; i < mx; i++){
        primes[i] = 1;
    }

    primes[1] = 1;
    primes[2] = 1;
    for(int i = 2; i < mx; i++){
        if(!primes[i])continue;
        for(int d = i+i; d < mx; d+=i){
            primes[d] = 0;
        }
    }
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



