#include <bits/stdc++.h>

using namespace std;

void solve(){
    int p1,c1,p2,c2; cin >> p1 >> c1 >> p2 >> c2;
    if(p1*c1 == p2*c2) cout << 0 << endl;
    if(p1*c1 > p2*c2) cout << -1 << endl;
    if(p2*c2 > p1*c1) cout << 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}