#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;
int nodes[MAX];
int res=0;
vector<int> vis(MAX);
vector<vector<int>> adj;

void dfs(int s, int l){
    nodes[l] = s;    
    vis[s] = 1;
    if(l >= 3 && s == nodes[0]) res++;  
    for(auto u : adj[s]) if(!vis[u]) dfs(u,l+1);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
}
    dfs(n,0);
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

