#include <bits/stdc++.h>

void solve();
const int MAX = 1e5;
int H[MAX];
int dp[MAX];
using namespace std;

int dpp(int p){
    if(p==2){
        dp[2] = abs(H[2] - H[1]);
        return dp[p];
}
    if(dp[p] != -1) return dp[p];
    dp[p] = min(dpp(p-1) + abs(H[p] - H[p-1]), dpp(p-2) + abs(H[p] - H[p-2]));
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
    for(int i =1;i<=n;i++){
        cin >> H[i];
        dp[i] = -1;
    }
    dp[1] = 0;
    cout << dpp(n) << "\n";
}