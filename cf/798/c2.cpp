#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
const int mx = 3e5 + 5;
int ans;
vector<int> filhos(mx),vis(mx);
vector<vector<int>> adj(mx);

int dfs(int v){
    vis[v] = 1;
    int temp=0;
    for(auto u : adj[v]) if(!vis[u]) temp += dfs(u);
    filhos[v] = temp+1;
    return temp + 1;
}  

void odfs(int v, int count){
    vis[v] = 1;
    vector<int> ch;
    for(auto u : adj[v]) if(!vis[u]) ch.push_back(u);
    if(ch.size() == 1) ans = max(ans,filhos[ch[0]] -1 +count);
    else if(ch.size() == 0) ans = max(ans,count);
    else{
        odfs(ch[0],filhos[ch[1]] -1+count);
        odfs(ch[1],filhos[ch[0]] -1+count);
    }
}
void solve(){
    int n; cin >> n;
    ans = 0;
    for(int i = 0; i <= n; i++){
        filhos[i] = 0;
        vis[i] = 0;
        adj[i].clear();
    }
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    dfs(1);
    for(int i = 0; i <= n; i++) vis[i] = 0;
    odfs(1,0);
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}
