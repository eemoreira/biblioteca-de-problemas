#include <bits/stdc++.h>

using namespace std;

void solve(){
    int p,r; cin >> p >> r;
    if(p==0) cout << "C" << endl;
    if(p==1 && r==0) cout << "B" << endl;
    if(p==1 && r==1) cout << "A" << endl;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0;
    }