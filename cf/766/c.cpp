#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

map<int,int> vis;
vector<int> ans(200005);
int s = -1,e = -1;
map<ii,int> edge;
void dfs(int v, vector<vector<int>> &a, int w){
    vis[v] = 1;
    for(auto u : a[v]){
        if(!vis[u]){
            ans[edge[ii(v,u)]] = w;
            if(u==e) return;
            if(w==2) dfs(u,a,3);
            else dfs(u,a,2);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1); 
    map<int,int> qnts;
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        qnts[a]++;
        qnts[b]++;
        ii p = ii(a,b);
        ii p1 = ii(b,a);
        edge[p] = i;
        edge[p1]= i;
    }
    for(int i = 0; i<=n; i++){
        if(qnts[i] > 2){
            cout << -1 << endl;
            return;
        }
    }
    s=-1,e=-1;
    for(int i = 1; i <= n; i++){
        if(qnts[i] == 1){
            if(s==-1) s = i;
            else e = i;
        }
    }
    ans[s] = 2;
    dfs(s,adj,2);
    for(int i = 1; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
    for(int i = 0; i <= n; i++){
        vis[i] =0;
        ans.clear();
        edge.clear();
    }
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tc; cin >> tc;
    while(tc--)
	solve();
	return 0;
}

