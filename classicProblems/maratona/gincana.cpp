#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;
    ll check=0;
    for(ll i = m; i > 0; i--){
        if(gcd(n,i) == 1) {
        cout << i << endl;
        check = 1;
        break;
        }
    }
    if(check == 0) cout << 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}