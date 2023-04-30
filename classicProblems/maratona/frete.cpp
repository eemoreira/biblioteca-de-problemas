#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

void solve(){
	int n,m; cin >> n >> m;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> vis(m);
	int dist[MAX];
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({w,b});
		adj[b].push_back({w,a});
	}
	for(int i = 1; i <= n;i++){
		dist[i] = INT_MAX;
	}
	
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		auto [u,t] = pq.top();
		pq.pop();
		if(u < dist[t]){
			dist[t] = u;
			for(int i = 0; i < adj[t].size(); i++){
				pq.push({adj[t][i].first + dist[t],adj[t][i].second});	
			}
		}
	}
	cout << dist[n] << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
