#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 100;
int x,n;
int dp[MAX + 5][1000005],pesos[MAX],vals[MAX];

void solve(){
    cin >> n >> x;
        for(int i =1; i<=n;i++){
        cin >> pesos[i] >> vals[i];
    }
    for(int i = 0; i<=x ; i++){
        dp[0][i] = (int)1000;   
    }
    for(int i = 0; i <= n;i++){
        dp[i][0] = vals[i];
    }
    for(int i = 1; i<=n;i++){
        for(int k=1; k<=x;k++){
            if(k - pesos[i] < 0){
                dp[i][k] = dp[i-1][k];
            }
            else{
                dp[i][k] = min(dp[i-1][k], dp[i][k-pesos[i]] + vals[i]);
        }   
        }
    }
    for(int i =0; i<=n;i++){
        for(int k = 0; k<=x; k++){
            cout << dp[i][k] << " ";
        }
        cout << endl;
    }
    cout << dp[n][x] << endl;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
