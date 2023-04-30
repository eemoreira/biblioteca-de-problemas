#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;

void solve(){
    int n,m; cin >> n >> m;
    int arr[MAX];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 1; i < n; i += 2){
        if(arr[i-1] > arr[i]) arr[i] = m - arr[i];
        if(arr[i-1] > arr[i]) cout << -1 << endl;
        if(arr[i-1] + arr[i] != m){
            sum += min(arr[i-1] + arr[i],m-arr[i-1] + arr[i]);
            arr[i] = 
        }
    } 
   cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;

}