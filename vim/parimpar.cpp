#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
int par[MAX + 5], impar[MAX + 5];

void solve(){
    int n; cin >> n;
    int j=0,k=0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a % 2 == 0) {
            par[j] = a;
            j++;
        }
        if(a % 2 == 1){
             impar[k] = a; 
             k++;
         }
}      
    sort(begin(par), begin(par) + j);
    sort(begin(impar), begin(impar) + k, greater<int>());
    for(int i = 0; i < j;i++) cout << par[i] << endl;
    for(int i = 0; i < k; i++) cout << impar[i] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

