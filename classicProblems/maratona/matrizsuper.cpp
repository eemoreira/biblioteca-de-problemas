#include <bits/stdc++.h>

const int MAX = 1000;
int arr[MAX][MAX];

using namespace std;

int cool(int l, int c){
    if(l <= 1 || c <= 1) return 0;
    int check = 1;
    for(int i=1;i<=l;i++){
        for(int k=1;k<=c;k++){
            if(arr[1][1] + arr[i][k] >= arr[1][k] + arr[i][1]){
                check =0;
                break;
            } 
        }
    }
    return check;
}

void solve(){
    int x,y; cin >> x >> y;
    for(int i=1;i<=x;i++){
        for(int k=1;k<=m;k++){
            cin >> arr[i][k];
        }
    }
    

}
int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        solve();
        return 0;
    }
