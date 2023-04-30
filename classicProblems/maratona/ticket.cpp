#include <bits/stdc++.h> 

using namespace std;

void solve(){
    int n; cin >> n;
    int arr[6];
    int a,b,c,d,e,f;
    a = n / 100000;
    b = (n%100000) / 10000;
    c = (n%10000) / 1000;
    d = (n%1000) / 100;
    e = (n%100) / 10;
    f = (n%10) / 1;
    if(a + b + c == d + e + f) cout << "YES" << endl;
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
