#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

void solve(){
	int n; cin >> n;
	int count=0;
	string s; cin >> s;
	for(int i = 0; i < n;i++){
		if(s[i] == '1') count++;
	}
	cout << count*(count + 1)/2 << endl;
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


