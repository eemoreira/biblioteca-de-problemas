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
#define eb emplace_back

int ok2321 = 0;

void solve(){
    int n,k; cin >> n >> k;
    vector<ll> t(n),state(n);
    for(auto&u:t)cin>>u;
    for(auto&u:state)cin>>u;
    ll ans = 0;
    for(int i = 0; i < n; i++) if(state[i]) ans+=t[i];
    vector<ll> dp(n);
    dp[0] = (!state[0] ? t[0] : 0);
    for(int i = 1; i < n; i++){
        if(state[i]) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] + t[i];
    }
    ll dif = dp[k-1];
    /* for(int i = 0; i < n ; i++) cout << dp[i] << ' '; */
    /* cout << endl; */
    for(int i = k; i < n; i++){
        dif = max(dif, dp[i] - dp[i-k]);
    }
    cout << ans + dif << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



