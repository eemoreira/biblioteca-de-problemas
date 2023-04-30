#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

void solve(){
	int n; cin >> n;
	map<string, int> mp;
	for(int i =0 ;i < n; i++){
		int type; cin >> type;
		string s; cin >> s;
		if(type == 1){
			int x; cin >> x;
			mp[s] += x;
		}
		if(type == 2) mp[s] = 0;
		if(type == 3) cout << mp[s] << endl;

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
