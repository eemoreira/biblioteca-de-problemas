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
 
int ok2321 = 0;
const int mx = 2e5 + 5;
int timer,l,n;
vi adj[mx];
vector<vi> up;
vi tin, tout;
 
void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u,v);
    }
    tout[v] = ++timer;
}
 
bool is_a(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v){
    if(is_a(u,v)) return u;
    if(is_a(v,u)) return v;
    for(int i = l; i >= 0; i--){
        if(!is_a(up[u][i],v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}
 
void preprocess(int root) {
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vi(l + 1));
    dfs(root, root);
}
 
int depth[mx];
bool vis[mx];

int deep(int v){
    vis[v] = true;
    depth[v] = 0;
    for(auto u : adj[v]){
        if(vis[u])continue;
        depth[v] = max(depth[v], deep(u)+1);
    }
    return depth[v];
}

void solve(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    preprocess(1);
    deep(1);
    int q; cin >> q;
    while(q--){
        int size; cin >> size;
        vi go(size);
        int fork = 0;
        int comp = 0;
        bool ok = true;
        for(auto &u : go) cin >> u;
        sort(all(go), [&](int a,int b){return depth[a] < depth[b];});
        int dpst = go[0];
        for(int i = 1; i < size; i++){
            int lcaa = lca(dpst,go[i]);
            /* cout << "dpts: " << dpst << " go: " << go[i] << ' ' << " lca: " << lcaa << '\n'; */
            if(lcaa != go[i]){
                if(fork){
                    if(lcaa == fork){
                        int olcaa = lca(go[i],comp);
                        if(olcaa != go[i] && olcaa != comp) ok = false;
                        if(olcaa == comp) comp = go[i];
                    }
                    else{
                        ok = false;
                    }
                }
                else{
                    fork = lcaa;
                    comp = go[i];
                }
            }
        }
        if(fork){
            for(auto u : go){
                int lcaa = lca(u,fork);
                if(depth[lcaa] <= depth[fork]) continue;
                ok = false;
            }
        }
        if(ok) cout << "yes\n";
        else cout << "no\n";
    }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



