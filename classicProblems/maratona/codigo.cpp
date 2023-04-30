#include<bits/stdc++.h>

const int MAX = 1e4;

using namespace std;

void solve(){
    int n; cin >> n;
    int arr[MAX];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < n - 2; i++){
        if(arr[i] == 1){
            if(arr[i+1] == 0 && arr[i+2] == 0) count++;
        }
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}