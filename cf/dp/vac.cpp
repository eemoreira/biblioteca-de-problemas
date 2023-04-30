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

const int mx = 1e5 + 5;

int dp[mx][4] , h[mx][4];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= 3; k++){
            dp[i][k] = 0;
            cin >> h[i][k];
        }
    }
    for(int i = 1; i <= 3; i++) dp[1][i] = h[1][i];
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= 3; k++){
            int t,s;
            if(k==1) t=2,s=3;
            if(k==2) t=1,s=3;
            if(k==3) t=1,s=2;
            dp[i][k] = max(dp[i-1][t],dp[i-1][s]) + h[i][k];
        }
    }
    int ans = 0;
    /* for(int i =1; i <= n; i++){ */
    /*     for(int k = 1; k <= 3; k++){ */
    /*         cout << dp[i][k] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    for(int i = 1; i <= 3; i++) ans = max(ans,dp[n][i]);
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



