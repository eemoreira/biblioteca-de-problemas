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

    int n, res = -1;
    cin >> n;

    vector<string> cartas(n);

    for(int i=0; i < n; i++){
        string temp;
        cin >> temp;
        cartas[i] = temp;
    }

    if(n >= 9){
        for(int i=0; i <= (n-9); i++){
            unordered_map<char, set<char>> freq;
            for(int k=i; k < (9 + i); k++){
                char carta, naipe;
                carta = cartas[k][0];
                naipe = cartas[k][1];
                freq[carta].insert(naipe);
                if(freq[carta].size() >= 3 && res == -1){
                    res = k + 1;
                }
            }
        }
        cout << res << endl; 
    }
    else{
        unordered_map<char, set<char>> freq;
        for(int i=0; i < n; i++){
            char carta, naipe;
            carta = cartas[i][0];
            naipe = cartas[i][1];
            freq[carta].insert(naipe);
            if(freq[carta].size() >= 3 && res == -1){
                res = i + 1;
            }
        }
            cout << res << endl;
        }
    }
