#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1005);
vector<int> wt(1005);
vector<int> freq(1005);
vector<int> vis(1005);
int cont,qnt;

void dfs(int v){
    vis[v] = 1;
    qnt++; 
    freq[wt[v]]++;
    for(auto u : adj[v]) if(!vis[u]) dfs(u);

}

void solve(){
    int numpi,c; cin >> numpi >> c;
    for(int i = 1; i <= numpi; i++){
        cin >> wt[i];
    }
    for(int i = 0; i < c; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= numpi; i++){
        if(!vis[i]){
            dfs(i);
            int maior=0;
            for(auto u : freq) maior = max(u,maior);
            cont += qnt - maior;
            freq.clear();
            qnt = 0;
        }
    }
    cout << cont << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
