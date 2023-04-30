#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    priority_queue<pair<int,int>> pq;
    int dist[12][12];
    vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++){
            dist[i][k] = INT_MIN;
        }
    }

    int xe,ye;cin>>xe>>ye;
    pq.push({xe,ye});
    while(!pq.empty()){
            auto [u,w] = pq.top();
            pq.pop();
            for(auto [i,o] : moves){
            if(u + i - xe > 0 && u + i -xe <= n && w + o -ye  > 0 && w + o - ye<= m){
                if(u+i - xe + w+o - ye > dist[u][w]){
                    dist[u][w] = u+i-xe+w+o-ye;        
                        pq.push({u+i-xe,w+o-ye});
                }   
            }
        }
    }
    int xf,yf; cin>>xf>>yf;
    cout << dist[xf][yf] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

