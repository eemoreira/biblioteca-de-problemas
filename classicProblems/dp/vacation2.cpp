#include <bits/stdc++.h>

const int MAX = 1e5;
int arr[MAX][3], dp[MAX][3], id[MAX];

using namespace std;

int dpp(int l, int c){
    if(dp[l][c] != -1) return dp[l][c];
    if(l < 0) return 0;
    int maior =0;
    for(int i=0;i<3;i++){
        if(i == c) continue;
        if(dpp(l-1,i) + arr[l][c] > maior) maior = arr[l][c] + dpp(l-1,i);
    }
    dp[l][c] = maior;
    return dp[l][c];
    
}



void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        for(int k=0;k<3;k++){
            cin >> arr[i][k];
            dp[i][k] = -1;
        }
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    cout << max(dpp(n-1,0),max(dpp(n-1,1),dpp(n-1,2))) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}