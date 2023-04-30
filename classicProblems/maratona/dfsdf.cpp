#include <bits/stdc++.h>

void solve();

using namespace std;

const int MAX = 202;
vector<vector<int>> adj(MAX);
vector<int> vis(MAX);
int res[MAX];
void dfs(int u){
    vis[u] = 1;
    res[u] = 1;
    for(auto v : adj[u]) if(!vis[v]) dfs(v);
    for(auto v : adj[u]) res[u] = max(res[u], res[v] + 1);
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    int s, t, p; cin >> s >> t >> p;
    vector<int> h(t+1);
    for(int i=1;i<=s;i++){
        cin >> h[i];
    }
    for(int i=1;i<=t;i++){
        int x,y; cin >> x >> y;
        if(h[x]==h[y]) continue;
        if(h[x] < h[y]) swap(x,y);
        adj[x].push_back(y);
    }
    dfs(p);
    cout << res[p] - 1 << "\n";
}
