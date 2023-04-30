#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

void solve(){
    int sums[100][100];
    int vals[4];
    for(int i = 0; i < 4; i++) cin >> vals[i];
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4 && k != i; k++){
            sums[i][k] = vals[i] + vals[k];
        }
    }
    int menor = INT_MAX;
    for(int i =1 ; i < 4; i++){
        for(int k = 0; k < 4 && k != i-1; k++){
            for(int d = 0; d < 4 && d != k && d != i; d++){
                if(abs(sums[i-1][k] - sums[i][d]) < menor) menor = abs(sums[i-1][k]
- sums[i][d]);
            }            
        }
    }
    cout << menor << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

