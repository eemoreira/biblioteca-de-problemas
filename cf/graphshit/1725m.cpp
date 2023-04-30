#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 2e5,INF=1e9;

vector<vector<pair<int,int>>> adj(mx);
int dist[mx];

void solve(){
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a}); 
    }
    for(int i = 0; i <= n; i++) dist[i] = INF;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
       auto [v,t] = pq.top();
       pq.pop();
       if(v < dist[t]){
            dist[t] = v;
            for(auto u : adj[v]){
                pq.push({u.first + dist[t], u.second});
            }
       }
    }
    for(int i = 2; i <= n; i++) cout << (dist[i] == INF ? -1 : dist[i]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

