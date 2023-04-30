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

const int mx = 1e3 + 5;

void solve(){
    int n,k,p; cin >> n >> k >> p;
    vector<ll> a(n);
    for(auto&u:a)cin>>u;
    vector<ll> keys(k);
    for(auto&u:keys)cin>>u;
    vector<vector<ll>> dp(k+1,vector<ll>(n+1));
    sor(keys);
    sor(a);
    for(int i = 0; i <= k; i++){
        for(int d = 0; d <= n; d++){
            dp[i][d] = 1e16;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < k; i++){
        for(int d = 0; d <= n; d++){
            dp[i+1][d] = min(dp[i+1][d],dp[i][d]); //dont take person for this key
            if(d < n) dp[i+1][d+1] = min(dp[i+1][d+1], max(dp[i][d], abs(a[d]-keys[i]) + abs(keys[i]-p))); //take person
        }
    }
    cout << dp[k][n] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



