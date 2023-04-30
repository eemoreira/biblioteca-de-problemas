#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<string, int> freq;
    for(int i = 0; i < n; i++){
        if(s.substr(i,2).size() == 2) freq[s.substr(i,2)]++;
    }
    int maior = INT_MIN;
    string res;
    for(auto u : freq){
        if(u.second > maior){
            maior = u.second;
            res = u.first;
        }
    }
    cout << res << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

