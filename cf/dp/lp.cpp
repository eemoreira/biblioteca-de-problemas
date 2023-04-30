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
const int mx = 1e5 + 5;
vector<vi> adj(mx);
int dp[mx];
vi ts;
bool vis[mx];

void dfs(int v){
    vis[v] = true;
    for(auto u : adj[v]){
        if(vis[u])continue;
        dfs(u);
    }
    ts.pb(v);
}

void solve(){
    int n,m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    /* for(auto u : ts) cout << u << ' '; */
    /* cout << endl; */
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(auto u : adj[ts[i]]){
            dp[ts[i]] = max(dp[ts[i]], dp[u]+1);
        }
        ans = max(dp[ts[i]], ans);
    }
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



