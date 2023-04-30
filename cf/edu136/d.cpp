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

int ok2321 = 1;
const int mx = 2e5 + 5;
vi adj[mx];
ll depth[mx];

vi go;
vi dad(mx);

void bfs(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto u : adj[cur]){
            depth[u] = depth[cur] + 1;
            q.push(u);
        }
    }
}

void dfs(int v, int h){
    go.pb(v);
    if(h <= (int) go.size()) dad[v] = go[(int)go.size() - h];
    for(auto u : adj[v]){
        dfs(u,h);
    }
    go.pop_back();
}

vi vis;

void mark(int v){
    vis[v] = 1;
    for(auto u : adj[v]) if(!vis[u]) mark(u);
}

void solve(){
    int n,q; cin >> n >> q;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
        depth[i] = 0;
    }
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        adj[p].pb(i);
    }
    bfs(1);
    vector<ii> order(n+1);
    for(int i = 1; i <= n; i++){
        order[i] = ii(depth[i],i);
    }

    /* for(auto u : order) cout << u.fst << ' ' << u.snd << '\n'; */
    sor(order);
    reverse(all(order));

    int l = 1, r = n-1;
    int ans = r;
    while(l <= r){
        int guess = (l+r)>>1;
        go.clear();
        for(int i = 1; i <= n; i++){
            dad[i] = 0;
        }
        dfs(1,guess);
        int bruh = 0;
        vis.assign(n+1, 0);
        for(auto u : order) if(!vis[u.snd] && u.fst > guess){
            bruh++;
            mark(dad[u.snd]);
        }
        if(bruh > q) l = guess + 1;
        else{
            r = guess - 1;
            ans = guess;
        }
    }
    cout << ans << '\n'; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



