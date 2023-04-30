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
int dp[mx];

void solve(){
    int n,k; cin >> n >> k;
    vi h(n+1);
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        cin >> h[i];
    }
    dp[1] = 0;
    for(int i = 1; i <= n; i++){
        for(int d = 1; d <= k; d++){
            if(d+i <= n) dp[i+d] = min(dp[i+d], dp[i] + abs(h[i]-h[i+d]));
        }
    }
    /* for(int i = 1; i <= n; i++) cout << dp[i] << ' '; */
    /* cout << endl; */
    cout << dp[n] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    i5
2 4 5 4 10
40 30 20 10 40
nt tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



