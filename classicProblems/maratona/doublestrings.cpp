#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;



void solve(){
    int n; cin >> n;
    map<string,int> mp;
    string s[100005];
    for(int i = 0;i < n; i++){
	cin >> s[i];
	mp[s[i]] = 1;
	}	
    	for(int k = 0; k < n; k++){
	int ok= 0;
	for(int i = 0; i < s[k].length(); i++){
		if(mp[s[k].substr(0,i)] && mp[s[k].substr(i)]) { // olha no mapa se tem a string cortada de 0 ate i e de i ate o final.
			cout << "1";
			ok = 1;
			break;
		}
	}
	if(!ok) cout << "0";
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
