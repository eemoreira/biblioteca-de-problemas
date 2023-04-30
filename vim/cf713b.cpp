#include <bits/stdc++.h>

using namespace std;

const int MAX = 400;

void solve(){
    int n; cin >> n;
    char grid[MAX][MAX];
    vector<pair<int,int>> pos;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cin >> grid[i][k];
            if(grid[i][k] == '*') pos.push_back({i,k}); 
        }        
    }
    auto [u,w] = pos[0];
    auto [r,t] = pos[1];  
    grid[u][t] = '*';
    grid[r][w] = '*'; 

    for(int i = 0; i < n; i++){
            if(u == r){
                if(grid[i][w] == '.' && grid[i][t] == '.' && i != u){
                    grid[i][w] = '*';
                    grid[i][t] = '*';
                    break;
            }
            }    
            else if(w == t){
                if(grid[u][i] == '.' && grid[r][i] == '.' && i != w){
                    grid[u][i] = '*';
                    grid[r][i] = '*';
                    break;
                }
            }
    }
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                cout << grid[i][k];
            }
            cout << endl;
        }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

