#include <bits/stdc++.h>

using namespace std;

int t;

void solve(){
    int n; cin >> n;
    int arr[50];
    for(int i= 1; i<=n; i++){
        cin >> arr[i];
    }
    int menor = INT_MAX;
    for(int i=1; i<=n; i++){
        if(arr[i] < menor) menor = arr[i];
    }
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum += arr[i] - menor;
    }
    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}