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
    long long n; cin >> n;
    cout << 0 << "\n";
    for(long long i =2;i<=n;i++){
    long long todasposicoes = i*i*(i*i -1)/2;
    long long posicoesQmata = 4*(i-1)*(i-2);
    cout << todasposicoes - posicoesQmata << "\n";
    }
}