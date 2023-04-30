#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5

int ok2321 = 1;
const int mx = 1e5 + 5;
vii adj[mx];
int px[mx];
bool vis[mx];
int b,a;
map<int,int> have;
bool ok = false;

void bfs(){
    queue<int> q;
    q.push(b);
    px[b] = 0;
    while(!q.empty()){
        int v = q.front();
        vis[v] = true;
        q.pop();
        for(auto [u,w] : adj[v]){
            if(vis[u])continue;
            px[u] = (w^px[v]);
            have[px[u]]++;
            q.push(u);
        }
    }
}

void dfs(int v,int x){
    vis[v] = true;
    /* cout << v << ' ' << x << '\n'; */
    if(have[x]) ok = true;
    for(auto [u,w] : adj[v]){
        if(vis[u] || b == u)continue;
        dfs(u,(w^x));
    }
}

void solve(){
    int n; cin >> n >> a >> b;
    ok = false;
    have.clear();
    for(int i = 0; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 0; i <= n; i++) vis[i] = false;
    for(int i = 0; i <= n; i++) px[i] = 0;
    for(int i = 0; i < n-1; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }
    bfs();
    for(int i = 0; i <= n; i++) vis[i] = false;
    /* for(int i = 1; i <= n; i++) cout << i << ' ' << px[i] << '\n'; */
    dfs(a,0);
    cout << (ok ? "YES\n":"NO\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



