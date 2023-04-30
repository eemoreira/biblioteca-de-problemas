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
const int mx = 1e3 + 5, mod = 1e9 + 7;
int dp[mx][mx];
char grid[mx][mx];

void solve(){
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            cin >> grid[i][k];
        }
    }
    for(int i = 0; i <= m; i++) grid[0][i] = '#', grid[n+1][i] = '#';
    for(int i = 0; i <= n; i++) grid[i][0] = '#', grid[i][m+1] = '#';
    dp[0][0] = 0;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(grid[i][k]=='#')continue;
            dp[i][k] = max((dp[i-1][k] + dp[i][k-1])%mod, dp[i][k]);
        }
    }
    /* for(int i = 1; i <= n; i++){ */
    /*     for(int k =1 ; k <= m; k++){ */
    /*         cout << dp[i][k] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    cout << dp[n][m]%mod << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



