#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5+5;

void solve(){
    int n;cin>>n;
    long long m= -1e17,res=0;
    long long arr[mx];
    map<int,int> sinal;
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
        if(arr[i] > 0) sinal[i] =1; 
    }
    m = arr[0];
    for(int i = 1; i < n; i++){
        if(sinal[i] == sinal[i-1]){
            m = max(m,arr[i]);
        }
        else {
            res += m;
            m = arr[i];
        }
    }
    res += m; 
    cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin>>t;
    while(t--)
    solve();
	return 0;
}

