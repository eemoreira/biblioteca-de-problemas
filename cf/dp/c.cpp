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
    int n; cin >> n;
    vector<vi> dp(n+1,vi(8));
    for(int i = 0; i <= n; i++){
        for(int k = 0; k < 8; k++){
            dp[i][k] = 1e9;
        }
    }
    dp[0][0] = 0;
    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        int cost; string s;
        cin >> cost >> s;
        int mask = 0;
        for(int d = 0; d < 3; d++){
            char c = 'C' - d;
            bool ok = 0;
            for(char bla : s) if(bla==c) ok = 1;
            if(ok){
                mask += (1 << d);
            }
        }
        for(int k = 0; k <= 7; k++){
            dp[i][k] = min(dp[i][k],dp[i-1][k]);
            dp[i][k | mask] = min(dp[i][k | mask], dp[i-1][k]+cost);
        }
    }

    ans = dp[n][7];
    cout << (ans == 1e9 ? -1 : ans) << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



