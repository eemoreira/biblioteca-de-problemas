#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
long long arr[2*MAX+5];

void solve(){
    int n; cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> arr[i];
    }
    int count=0;
    for(int i=1;i<n;i++){
        for(int j = i+1; j <= n; j++){
            if(arr[i] < i && i < arr[j] && arr[j] < j) count++;
        }
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
