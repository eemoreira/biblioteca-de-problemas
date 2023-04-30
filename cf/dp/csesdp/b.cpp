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
const int mx = 1e6+5;
int dp[mx];

void solve(){
    int n,c; cin >> n >> c;
    for(int i = 1; i <= c; i++) dp[i]=1e9;
    dp[0] = 0;
    vi have(n);
    for(auto&u:have)cin>>u;
    for(int i = 1; i <= c; i++){
        for(int k = 0; k < n; k++){
            if(have[k] <= i) dp[i] = min(dp[i-have[k]]+1,dp[i]);
        }
    }
    cout << (dp[c] == 1e9 ? -1 : dp[c]) << endl;

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



