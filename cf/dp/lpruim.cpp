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
vector<vi> adj(mx);
int dp[mx];

int dfs(int v){
    for(auto u : adj[v]) dp[v] = max(dfs(u)+1, dp[v]);
    return dp[v];
}

void solve(){
    int n,m; cin >> n >> m;
    map<int,int> child;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        child[v] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(!child[i]) ans = max(dfs(i),ans);
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



