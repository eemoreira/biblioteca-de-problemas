#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 1e5;

void solve(){
    ll n; cin >> n;
    ll chegada[MAX],saida[MAX];
    ll maxdif = INT_MIN;
    ll menorchegada,maiorsaida;
    for(ll i =0;i<n;i++){
        cin >> chegada[i] >> saida[i];
        if(chegada[i] - saida[i] > maxdif){
            maxdif = chegada[i] - saida[i];
            menorchegada = chegada[i];
            maiorsaida = saida[i];
        }
    }
    ll count = 0;
    ll check = 0;
    for(ll i=0;i<n;i++){
        if(chegada[i] < maiorsaida){
            check = 1;
            menorchegada = chegada[i];
        }
        if(saida[i] < maiorsaida){
            check = 1;
            maiorsaida = saida[i];
        }
        if(check) {
            count++;
            check = 0;
        }
    }
    cout << count << endl;
    

}

ll main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}