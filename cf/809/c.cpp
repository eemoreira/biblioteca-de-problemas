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

int ok2321 = 1;
const int mx = 1e5 + 5;
ll dp[mx];

void solve(){
    int n; cin >> n;
    double cool = (n-1)/2;
    vector<ll> a(n);
    for(auto &u : a) cin >> u;
    vector<ll> amount(n+1);
    amount[0] = amount[n] = 1e17;
    for(int i = 1; i < n-1; i++){
        amount[i] = max(0LL , max(a[i-1],a[i+1]) - a[i] + 1);
        /* cout << i << ' ' << amount[i] << endl; */
    }
    ll ans = 0;
    if(n&1){
        for(int i = 1; i < n ; i+=2) ans += amount[i];
        cout << ans << endl;
    }
    else{
        ll total = 0;
        for(int i = 1; i < n-1; i+=2){
            total += amount[i];
            /* cout << total << endl; */
        }
        ans = total;
        for(int i = n-2; i > 0; i-=2){
            total -= amount[i-1];
            total += amount[i];
            /* cout << total << ' ' << i << ' ' << i-1 << endl; */
            ans = min(ans,total);
        }
        cout << ans << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



