include <bits/stdc++.h>
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

const int mx = 2e5 + 5;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char,int> tem;
    for(int i = 0; i < k; i++){
        char c; cin >> c;
        tem[c]++;
    }
    ll dp[mx];
    dp[0] = 0;
    dp[1] = 1;
    ll ans = 0;
    int b=2;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + b;
        b++;
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        if(!tem[s[i]]){
            ans+=dp[t];
            t = 0;
            continue;
        }
        t++;
    }
    cout << ans+dp[t]<< endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



