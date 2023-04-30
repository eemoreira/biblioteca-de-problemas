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
    int n, s; cin >> n >> s;
    vector<int> saldo(n);
    saldo[0] = s;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        saldo[i] = saldo[i-1] + a;
    }
    int menor = saldo[0];
    for(int i=0;i<=n;i++){
        if(saldo[i] < menor) menor = saldo[i];
    }
    cout << menor << "\n";
}