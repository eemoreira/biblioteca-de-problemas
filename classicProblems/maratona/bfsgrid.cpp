#include <bits/stdc++.h>

const int MAX = 1000;

using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    char grid[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin >> grid[i][k];
        }
    }
    int check = 0;
    int menor = INT_MAX;
    vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> dist(n,vector<int>(m));
    dist[0][0] = 0;
    deque<pair<int,int>> dq;
    vector<vector<int>> vis(n,vector<int>(m));
    auto s = make_pair(0,0);
    dq.push_front(s);
    while(!dq.empty()){
        auto usando = dq.front();
        auto sf = usando.first;
        auto ss = usando.second;
        if(!dq.empty()) dq.pop_front();
        for(auto [u,w] : moves){
            if(u + sf < 0 || w + ss < 0) continue;
            if(u + sf >= n || w + ss >= m)continue;
            if(grid[u+sf][w+ss] == '#') continue;
            if(grid[u+sf][w+ss] == '.'&& !vis[u+sf][w+ss]) {
                dq.push_front(make_pair(u+sf,w+ss));
                dist[u+sf][w+ss] = 1 + dist[sf][ss];
                vis[u+sf][w+ss] = 1;
        }
            if(grid[u+sf][w+ss] == 'E'){
                dist[u+sf][w+ss] = 1 + dist[sf][ss];
                check = 1;
                if(dist[u+sf][w+ss] < menor) menor = dist[u+sf][w+ss];
            }
        }
        }
        if(!check) cout << "no path" << endl;
        else cout << menor << endl;
        }

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0;
    }
