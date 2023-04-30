#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n; cin>>n;
    string s;
    int count=0;
    int ok = 0;
    while(n != 0){
        if(n < 0){
            cout << "IMPOSSIBLE" << endl;
            ok = 1;
            break;
        }
        if(n % 2 == 0 && n >= 2){
            s.push_back('A');
            n-=2;
        }
        else if(n == 1){
            s.push_back('A');
            n--;
        }
        else {
            s.push_back('B');
            n--;
        }
    }
    if(s[s.size() - 1] != 'B') s.push_back('B');
    if(!ok) cout << s << endl;
    
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

