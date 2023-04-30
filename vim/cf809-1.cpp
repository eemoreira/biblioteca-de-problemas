#include <bits/stdc++.h>

using namespace std;

const int MAX = 110;

void solve(){
    int n,m; cin >> n >> m;
    vector<char> s(m+1);
    vector<int> st(n);
    map<char, int> mp;
    for(int i = 1; i <= m; i++){
        s[i] = 'B';
        mp[s[i]] = 0;
}
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        st[i] = a;
}
    for(auto u : st){
        if(!mp[s[u]] && !mp[s[m+1-u]]){
            if(u < m+1-u){
                s[u] = 'A';
                mp[s[u]] = 1;
            }
           else{
                s[m+1-u] = 'A';
                mp[s[m+1-u]] = 1;
             }
    }
        else{
            if(!mp[s[u]]){
                s[u] = 'A';
                mp[s[u]] = 1;
        }
            if(!mp[s[m+1-u]]){
                s[m+1-u] = 'A';
                mp[s[m+1-u]] = 1;
        }
}
}
    for(int i = 1; i <= m; i++) cout << s[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
    while(tc--){
        solve();
        cout << endl;
	}
    return 0;
}

