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
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mx = 2e5 + 5;

bool vis[mx];
vector<vi> adj(mx);
int dfs(int v){
    vis[v] = true;
    for(auto u : adj[v]) if(!vis[u]) return dfs(u) + 1;
    return 1;
}
void solve(){
    int n; cin >> n;
    int ok = 1;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = false;
    }
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        if(a == b || adj[a].size() > 2 || adj[b].size() > 2) ok = 0;
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        ok &= (dfs(i)%2==0);
    }
    cout << (ok?"yes":"no") << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



