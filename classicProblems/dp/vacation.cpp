#include <bits/stdc++.h>

void solve();

using namespace std;

const int MAX = 1e5;
int arr[MAX][3], dpid[MAX];
vector<int> dp(MAX);

int dpp(int p, int x){
    if (p==x) return dp[p];
    if(dp[p] != -1) return dp[p];
    int maior2 = arr[p][0];
    for(int i=0;i<3;i++){
        if(arr[p][i] > maior2 && dpid[p] != dpid[p-1]){
            maior2 = arr[p][i];
        }
    }
    dp[p] = dpp(p-1, x) + maior2;
    return dp[p];
    }

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        for(int k=0;k<3;k++){
            cin >> arr[i][k];
        }
        dp[i] -= 1;
    }
    int idmaior = arr[0][0];
    int maiorUltimo = arr[n][0];

    for(int i=0;i<3;i++){
        if(arr[0][i] > idmaior) idmaior = i;
        if(arr[n][i] > maiorUltimo) maiorUltimo = arr[n][i];
    }
    dp[n] = maiorUltimo;
    dpid[0] = idmaior;
    for(int f=1;f<n;f++){
        int maior = arr[f][0];
        int idmaior2 =0;
        for(int k=0;k<3;k++){
            if (arr[f][k] > maior && k != dpid[f-1]) idmaior2 = k;
        }   
    dpid[f] = idmaior2;
    }
    cout << dpp(n,n) << "\n";
}