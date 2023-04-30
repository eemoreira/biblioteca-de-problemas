#include <bits/stdc++.h>

const int MAX = 1000;
int arr[MAX], dp[MAX], n,store[MAX][MAX], dp2[MAX];
vector<int> res;

using namespace std;

void res(int x){
    for(int i = 0;i<x; i++){
        cout << store[i][x] << endl;
    }
}

int cansum(int p){
    if(dp[p] != -1) return dp[p];
    if(p < 0) return 0;
    for(int i=0;i<n;i++){
            if(cansum(p-arr[i])){
            dp[p] = 1;
            return dp[p];
    }
    }
    dp[p] = 0;
    return dp[p];
}

int howsum(int p){
    if(dp2[p] != -1) return dp2[p];
    if(p == 0) return dp2[p];
    if(p < 0) return -1;
    for(int i=0;i<n;i++){
        howsum(p - arr[i]);
        if(howsum(p-arr[i]) != -1){
            res.push_back(arr[i]);
            res.push_back(howsum(p-arr[i]));
            return res;
        }
    }
    return ;
}


void solve(){
    int sum; cin >> n >> sum;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        }
    for(int i =0;i<MAX;i++){
        dp[i] = -1;
        dp2[i] = -1;
    }
    dp[0] = 1;
    //cout << cansum(sum) << "\n";
    howsum(sum);
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}
