#include <bits/stdc++.h>
#define ll long long
void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    int s=-3;
    for(int i=0;i<4;i++){
        int t; cin >> t;
        s += t;
    }
    cout << s << "\n";

}