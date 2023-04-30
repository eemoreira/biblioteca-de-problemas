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

void solve(){
    int n; cin >> n;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        a.eb(x,y);
    }
    ll ma = 0;
    for(auto u : a) ma = max(ma, max(u.fst,u.snd));
    ll ans = 2*ma;
    for(auto u : a){
        int mi = min(u.fst,u.snd);
        ans += 2*mi;
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



