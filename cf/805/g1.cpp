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
vi adj[mx];
bool vis[mx];
vi depth(mx);

set<int> st;
vi go;

bool dfs(int v,map<int,int>&check, set<int> &s){
    if(v == -1) return false;
    go.pb(v);
    if(check[v]) st.insert(v);
    vis[v] = true;
    if(s == st) return true;
    bool ok = false;
    for(auto u : adj[v]){
        if(vis[u])continue;
        ok |= dfs(u,check,s);
    }
    st.erase(go[(int)go.size()-1]);
    go.pop_back();
    return ok;
}

int deep(int v){
    vis[v] = true;
    int cnt = 0;
    for(auto u : adj[v]){
        if(vis[u])continue;
        cnt = max(cnt,deep(u)+1);
    }
    return depth[v] = cnt;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++) vis[i] = false;
    deep(1);
    int q; cin >> q;
    while(q--){
        int size; cin >> size;
        st.clear();
        set<int> stt;
        map<int,int> check;
        int node=-1,mi=inf;
        for(int i = 0; i < size; i++){
            int a; cin >> a;
            if(depth[a] < mi){
                node = a;
                mi = depth[a];
            }
            stt.insert(a);
            check[a]++;
        }
        for(int i = 0; i <= n; i++) vis[i] = false;
        if(dfs(node,check,stt)) cout << "YES\n";
        else cout << "NO\n";
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



