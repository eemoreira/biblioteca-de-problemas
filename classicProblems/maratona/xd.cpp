#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> wincon = {{0,1},{0,2},{1,3},{1,2},{2,3},{2,4},{3,0},{3,4},{4,1},{4,0}};

void solve(){
	int n; cin >> n;
	int countd=0;
	int countx=0;
	map<pair<int,int>, int> mp;
	for(auto u : wincon){
		mp[u] = 1;
	}
	for(int i = 0; i< n; i++){
		int d, x; cin >> d >> x;
		auto u = make_pair(d,x);
		if(mp[u]) countd++;
		else countx++;
	}
	if(countx > countd) cout << "xerxes" << endl;
	if(countd > countx) cout << "dario" << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

