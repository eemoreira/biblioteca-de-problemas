#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

void solve(){
	int n,x; cin >> n >> x;
	int arr[2*MAX];
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	        mp[arr[i]] = i;	
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
