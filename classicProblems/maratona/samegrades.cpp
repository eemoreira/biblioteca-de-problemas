#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e5;

void solve(){
	map<int, int> mp;
	ll arr[MAX];
	int n, m; cin >> n >> m;
	for(int i = 0; i < n;i++){
		cin >> arr[i];
		mp[arr[i]] = 1;
	}
	for(int i = 0; i < m; i++){
		int a; cin >> a;
		if(mp[a]) cout << "YES" << endl;
		else {
			cout << "NO" << endl;
			mp[a] = 1;
	}
}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
	while(tc--){
	solve();
	}
	return 0;
}
