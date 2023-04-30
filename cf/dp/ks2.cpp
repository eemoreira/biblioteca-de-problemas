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
int dp[mx][105];
int n,w;

void solve(){
    cin >> n >> w;
    vector<ii> wi(n+1);
    for(int i = 1; i <= n; i++){
        int a,b; cin >> a >> b;
        wi[i] = ii(a,b);
    } 
    for(int i = 0; i < mx; i++){
        for(int k = 0; k <= n; k++){
            dp[i][k] = 1e9 + 5;    
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < mx; i++){
        for(int k = 1; k <= n; k++){
            dp[i][k] = min(dp[i][k],dp[i][k-1]);
            if(wi[k].snd <= i) dp[i][k] = min(dp[i][k-1], dp[i-wi[k].snd][k-1] + wi[k].fst);
        }   
    }
    int ma = -1e9 - 5;
    for(int i = 0; i <= 140; i++){
        for(int k = 1; k <= n; k++){
            cout << dp[i][k] << ' ';
        }
        cout << '\n';
    }
    for(int i = 0; i < mx; i++){
        if(dp[i][n] > w) continue;
        ma = max(i,ma);
    }
    cout << ma << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}




