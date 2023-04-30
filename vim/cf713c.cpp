#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b; cin >> a >> b;
    string s; cin >> s;
    int ok = 1;
    if((a+b) % 2 == 1) ok = 0;
    
    char mid;
    if(!ok) {
        if(s[(a+b)/2] == '?') s[(a+b)/2] =1;
        mid = s[(a+b)/2];
        s.erase((a+b)/2 ,1);    
    }
    string as = s.substr(0,s.size() / 2);
    string bs = s.substr(s.size() / 2, s.size());
    
    
    int l = as.size();
    for(int i = 0; i < l; i++){
        if(as[i] != '?' && bs[l-i-1] != '?') continue;
        else if(as[i] == '1' && bs[l-i-1] == '?') bs[l-i-1] = '1';
        else if(as[i] == '0' && bs[l-i-1] == '?') bs[l-i-1] = '0';
        else if(as[i] == '?' && bs[l-i-1] == '1') as[i] = '1';
        else if(as[i] == '?' && bs[l-i-1] == '0') as[i] = '0';
        else{
            if(a > b){
                as[i] = '1';
                bs[l-i-1] = '1';
            }
            else{
                bs[l-i-1] = '0';
                as[i] = '0';
            }
}
    }
    if(ok) cout << as + bs << endl;
    else cout << as + mid + bs << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    int t; cin >> t;
    cin.tie(0);
    while(t--)
	solve();
	return 0;
}

