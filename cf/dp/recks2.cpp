#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 0;
const int mx = 1e5 + 5;
int v[105],dp[mx][105],w[105];

int ks(int val, int n){
    if(n == 0){
        return val == 0 ? 0 : 1e9 + 6;
    }
    if(dp[val][n] != 1e9 + 5) return dp[val][n];
    /* cout << "dp["<<val<<"]["<<n<<"]\n"; */
    dp[val][n]= ks(val,n-1);
    if(v[n] <= val) dp[val][n]= min(dp[val][n], ks(val-v[n],n-1) + w[n]);
    return dp[val][n];
}

void solve(){
    int n,ww; cin >> n >> ww;
    int maxx = 0;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
        maxx += v[i];
    }
    for(int i = 0; i < mx; i++){
        for(int k = 0; k <= n; k++){
            dp[i][k] = +1e9 + 5;
        }
    }
    dp[0][0] = 0;
    for(int i = maxx; i >= 0; i--){
        if(ks(i,n) <= ww){
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



