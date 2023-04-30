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
    string s;
    getline(cin >> ws, s);
    string letras = "ACGT";
    vector<int> count(s.size());
    int contador=0;
    vector<bool> usado(s.size());
    for(int i=0; i<4; i++){
        for(int k=0;k<s.size();k++){
            if(letras[i] == s[k] && !usado.at(k)){
                contador++;
                count.at(k) = contador;
                usado.at(k) = true;
            }
            else{
                contador=0;
            }
        }
        
    }
    int maior = count[0];
    for(int i=0;i<count.size();i++){
        if(count[i] > maior){
            maior = count[i];
        }
    }
    cout << maior << endl;
}