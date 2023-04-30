#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    map<string, int> mp;
    string word;
    for(int i = 0; i < n - 2; i++){
        string s; cin >> s;
        mp[s] = 1;
        word.append(s);   
 }
    word.append("ZZ");
    for(int i = 0; i < word.size() - 2; i++){
        if(word[i] == word[i+1] && word[i] == word[i+2]){
            cout << word[i];
            i+=2;
        }   
        else cout << word[i];
}
cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
	while(t--) solve();
	return 0;
}

