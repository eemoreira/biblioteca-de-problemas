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
vector<vi> adj(mx),revadj(mx);
ii costs[mx];
ll pf[mx],pfb[mx];
int parent[mx];
vll ans(mx);
vll dist(mx);

void bfs(int v){
    pf[v] = 0;
    queue<int> q;
    dist[v] = 0;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto u : adj[cur]){
            q.push(u);
            pf[u] = pf[cur] + costs[u].fst;
            pfb[u] = pfb[cur] + costs[u].snd;
            dist[u] = dist[cur] + 1;
        }
    }
}

vi go;

void dfs(int v){
    go.pb(v);
    int l = 0;
    int r = (int)go.size()-1;
    cout << "vector: ";
    for(auto u : go) cout << u << ' ';
    cout << '\n';
    while(l <= r){
        int mid = (l+r)/2;
        if(pfb[go[mid]] <= pf[v]){
            l = mid + 1;
            ans[v] = dist[go[mid]];
        }
        else{
            r = mid - 1;
        }
    }
    for(auto u : adj[v]){
        dfs(u);
    }
    go.pop_back();
}


void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
        costs[i] = ii(0,0);
    }
    for(int i = 2; i <= n; i++){
        int parentt,a,b; cin >> parentt >> a >> b;
        adj[parentt].pb(i);
        costs[i] = ii(a,b);
    }
    bfs(1);
    dfs(1);
    for(int i = 2; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



