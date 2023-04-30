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
const int mx = 1e3 + 5;
map<ii, vector<ii>> adj;
map<ii, bool> vis;

int dfs(ii v){
    vis[v] = true;
    cout << v.fst << ' ' << v.snd << endl;
    int ok = 0;
    for(auto u : adj[v]) if(!vis[u]){
        ok = 1;
        dfs(u);
    }
    return ok;
}

void solve(){
    int n; cin >> n;
    vector<ii> a;
    map<ii,int> tem;
    for(int i = 0 ; i < n; i++){
        int u,v; cin >> u >> v;
        a.pb(ii(u,v));
        tem[ii(u,v)] = 1;
    }
    for(auto u : a){
        if(tem[ii(u.fst,u.snd+1)]) adj[u].pb(ii(u.fst,u.snd+1));
        if(tem[ii(u.fst+1,u.snd)]) adj[u].pb(ii(u.fst+1,u.snd));
        if(tem[ii(u.fst-1,u.snd)]) adj[u].pb(ii(u.fst-1,u.snd));
        if(tem[ii(u.fst, u.snd-1)]) adj[u].pb(ii(u.fst, u.snd-1));
        if(tem[ii(u.fst-1, u.snd-1)]) adj[u].pb(ii(u.fst-1, u.snd-1));
        if(tem[ii(u.fst+1, u.snd+1)]) adj[u].pb(ii(u.fst+1, u.snd+1));
    }
    ll ans = 0;
    for(auto u : a) if(!vis[u]){
        ans += dfs(u);
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



