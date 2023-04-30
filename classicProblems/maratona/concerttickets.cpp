#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*1e5;

void solve(){
    int n, m; cin >> n >> m;
    int price[MAX],maxprice[MAX];
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    sort(begin(price),end(price));
    for(int i=0;i<m;i++){
        cin >> maxprice[i];
    }
    for(int i=0;i<m;i++){
        for(int  k=0;k<n;k++){
        while(maxprice[i] < price[k]){
            
        }
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}