#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e5;
ll h[MAX];

void solve(){
    int n,m ; cin >> n >> m;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,
greater<pair<ll,ll>>>  pq;
    vector<vector<pair<ll, int>>> adj(n+1);
    for(int i = 1; i <= n; i++){ 
        cin >> h[i];
    } 
    if(h[1] > h[2]) adj[1].push_back({h[1] - h[2], 2});
    else adj[1].push_back({0,2});
    if(h[n] > h[n-1]) adj[n].push_back({h[n] - h[n-1], n-1});
    else adj[n].push_back({0,n-1});
    for(int i = 2; i < n; i++){
        if(h[i] > h[i-1]) adj[i].push_back({h[i] - h[i-1],i-1}); 
        else adj[i].push_back({0,i-1});
        if(h[i] > h[i+1]) adj[i].push_back({h[i] - h[i+1], i+1});
        else adj[i].push_back({0,i+1});
     }
    while(m--){
    int p, q; cin >> p >> q;
    pq.push({0,p});
    ll dist[MAX];
    for(int i = 0; i <= n; i++) dist[i] = 1e9; 
    while(!pq.empty()){
        auto [u,t] = pq.top();
        pq.pop();
        if(u < dist[t]){
            dist[t] = u;
            for(int i = 0; i < adj[t].size() ; i++){
                pq.push({adj[t][i].first + dist[t],adj[t][i].second});
            }
    
        }
    }
    cout << dist[q] << endl;
    }      
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

