#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    getline(cin >> ws, s);
    if( s == "YES" || s == "yes" || s == "yES" || s == "yeS" || s=="Yes" || s == "YEs"  || s == "YeS" || s == "yEs") cout << "YES" << endl;
    else cout << "NO" << endl;
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