#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r, d; cin >> l >> r >> d;
    if(r <= 50 || r <= l) cout << "N" << endl;
    else{
        if(r > l && r > d) cout << "S" << endl;
        if(r > l && r <= d) cout << "N" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}