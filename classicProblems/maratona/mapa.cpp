#include <bits/stdc++.h>

using namespace std;

vector<pair<int ,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
int l, c;
const int MAX = 105;
char grid[MAX][MAX];

void solve(){
	cin >> l >> c;
	vector<vector<int>> vis(l, vector<int> (c));
	queue<pair<int,int>> q;
	for(int i = 0; i < l; i++){
		for(int k=0 ; k < c; k++){
			cin >> grid[i][k];
			if(grid[i][k]== 'o'){
			       	q.push(make_pair(i,k));
				vis[i][k] = 1;
			}
		}
	}
	pair<int,int> res;
	while(!q.empty()){
		auto usando = q.front();
		q.pop();
		for(auto [u,w] : moves){
			auto x = usando.first + u;
			auto y = usando.second + w;
			if(x >= 0 && x < l && y >= 0 && y < c && !vis[x][y]){
				if(grid[x][y] == 'H'){
				       	q.push(make_pair(x,y));
					res = make_pair(x,y);
					vis[x][y] = 1;
				}
			}
		}
	}
	
	 cout << res.first + 1 << " " << res.second + 1 << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
