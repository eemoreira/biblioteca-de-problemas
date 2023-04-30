#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 100;
int dp[MAX + 5][1000000+5];

void solve(){
    int x,n; cin >> n >> x;
    int arr[MAX+5];
    for(int i =1; i<=n;i++){
        cin >> arr[i];
    }
    for(int i = 0; i<=x ; i++){
        dp[0][i] = (int)1e9;
    }
    for(int i = 0; i <= n;i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i<= n; i++){
        for(int  k = 1; k <= x; k++){
            if(k - arr[i] < 0){
                dp[i][k] = dp[i-1][k];
            }
            else{
                dp[i][k] = min(dp[i-1][k], dp[i][k-arr[i]] + 1);
            }
        }
    }
    if(dp[n][x] == 1000000000) cout << -1 << endl;
    else cout << dp[n][x] << endl;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
