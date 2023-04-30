#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int h1 = 3;
    int h2=2;
    int h3 =1; 
    while(h1 + h2 + h3 < n){
        h1++;
        if(h1 + h2 + h3 < n){
            h2++;
            if(h1+h2+h3 < n){
                h3++;
            }
            else break;
        }
        else break;
    }   
    cout << h2 << ' ' << h1 << ' ' << h3 << endl;
}
    
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

