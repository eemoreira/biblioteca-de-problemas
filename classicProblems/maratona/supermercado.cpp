#include <bits/stdc++.h>

int MAX = 100;

using namespace std;

void solve(){
    int n; cin >> n;
    float arr[MAX];
    for(int i = 0;i<n;i++){
        float preco, peso; cin >> preco >> peso;
        arr[i] = 1000 * preco/peso;
    }
    float menor = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] < menor) menor = arr[i];
    }
    printf("%.2f\n", menor);

}

int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        solve();
        return 0;
    }
