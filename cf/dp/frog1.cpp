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
const int mx = 1e5+5;
int dp[mx];

void solve(){
    int n; cin >> n;
    vi h(n+1);
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);
    for(int i = 3; i <= n; i++){
        /* cout << "i: " << i << ' ' << dp[i-1]+abs(h[i]-h[i-1]) << ' ' << dp[i-2]+abs(h[i-2]-h[i]) << ' ' << dp[i] << endl; */
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), min(dp[i-2]+abs(h[i-2]-h[i]), dp[i]));
        /* cout << dp[i] << endl; */
    }
    /* for(int i = 1; i <= n; i++) cout << dp[i] << ' '; */
    /* cout << endl; */
    cout << dp[n] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



