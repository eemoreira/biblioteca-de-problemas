#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    string s,t;
    cin >> s >> t;
    if(s==t){
        cout << "Yes" << endl;
        return;
    }   
    for(int i = 1; i < s.size() ; i++){
        swap(s[i-1],s[i]);
        if(s==t){
            cout << "Yes" << endl;
            return;
        }
        swap(s[i-1],s[i]);
    }   
    cout << "No" << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

