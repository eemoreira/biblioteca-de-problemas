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
int dp[2005][2005];

void solve(){
    int v0, vf; cin >> v0 >> vf;
    int t,d; cin >> t >> d;

    dp[0][v0] = v0;
    for(int i = 1; i <= t; i++){
        for(int h = 0; h <= 2000; h++){
            int mx = 0;
            for(int k = -d; k <= d; k++){
                if(h+k < 0 || h+k > 2000)continue;
                mx = max(dp[i-1][h+k],mx);
                if(mx==0) dp[i][h] = 0;
                else dp[i][h] = mx + h;
            }
        }
    }
    /* for(int i = 0; i <= t; i++){ */
    /*     for(int k = 0; k <= 15; k++){ */
    /*         cout << dp[i][k] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    cout << dp[t-1][vf] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



