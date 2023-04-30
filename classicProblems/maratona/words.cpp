#include <bits/stdc++.h>

using namespace std;

void solve(){
	map<string, int> mp;
	string s[5];
	int n; cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	for(int i=0;i<n;i++){
		int sum = 0;
		for(auto u : s[i]){
			sum += u - 64; 
		}
		mp[s[i]] = sum;
	}
	for(auto u : mp){
		cout << u.second << endl;
		}
	}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
