#include <bits/stdc++.h>

void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){

    long long int n; cin >> n;
    cout << n << " ";
    while(n != 1){
    if(n % 2 == 0){
        n = n/2;
    }
    else{
        n = 1 + 3*n;
    }
    cout << n << " ";
    }
}