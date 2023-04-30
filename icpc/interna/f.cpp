#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin >> s;
    map<int ,int> freq;
    for(auto u : s){
        freq[(int)u - '0']++;
    }
    int menorfreq=1e9,menor;
    for(int i = 1; i <= 9; i++){
        if(!freq[i]){
            cout << i << endl;
            return;
        }
    }
    if(!freq[0]){
        cout << 10 << endl;
    }
    else{
        for(int i = 9; i>= 1; i--){
            if(freq[i] <= menorfreq){
                menor = i;
                menorfreq = freq[i];
            }
        }
        if(freq[0] < menorfreq){
            cout << 1;
            for(int k = 0; k <= freq[0]; k++){
                cout << 0;
            }
            cout << endl;
            return; 
        }
        else{
            for(int k = 0; k <= menorfreq; k++){
                cout << menor;
            }
            cout << endl;
            return;
        }        
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

