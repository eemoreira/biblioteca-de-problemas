#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
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
vi adj[mx];
int ans = 1e9 + 5;
bool vis[mx];

int dfs(int v){
    if(v == -1) return 0;
    vi all;
    int cnt = 1e9+5;
    vis[v] = true;
    for(auto u : adj[v]){
        if(vis[u])continue;
        int t = dfs(u);
        cnt = min(cnt,t);
        all.pb(t);
    }
    if((int)all.size() > 1){
        sor(all);
        ans = min(ans,all[1]+all[0]);
    }
    return (cnt == 1e9+5 ? 1 : cnt+1);
}

void solve(){
    int n; cin >> n;
    int root = -1;
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++) if(root == -1 && (int)adj[i].size() > 1) root = i;
    dfs(root);
    cout << (ans == 1e9 + 5 ? 1 : ans) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


