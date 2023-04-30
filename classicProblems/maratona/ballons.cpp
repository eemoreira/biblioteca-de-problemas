#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n; cin >> n;
    string s;
    getline(cin >> ws, s);
    sort(begin(s), end(s));
    int count = 2;
    int check = 0;
    for(int i = 1;i < s.size(); i++){
        count++;
        for(int k = i-1; k >=0 ; k--){
            if(s[i] == s[k]) check = 1;
        }
        if(!check) count++;
        check = 0;
    }
    cout << count << endl;
    
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