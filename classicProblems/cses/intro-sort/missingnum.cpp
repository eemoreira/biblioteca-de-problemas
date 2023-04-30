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
    long long int numeros, sumMissing=0;
    for(int i=0;i<n-1;i++){
        cin >> numeros;
        sumMissing += numeros;
    }
    const long long int sum = (n*(n+1))/2;
    cout << sum - sumMissing << endl;
}