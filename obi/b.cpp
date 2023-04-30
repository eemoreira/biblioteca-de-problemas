#include <bits/stdc++.h>

using namespace std;

const int mx = 1e4+5;

void solve(){
    int n; cin>>n;
    int arr[mx];
    int mdif = INT_MIN;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        
    }
    sort(begin(arr),begin(arr) +n);
    if(arr[0] > 8){
        cout << "N" << endl;
        return;
    }   
    for(int i = 1; i <= n; i++){
        if(arr[i] > 8 + arr[i-1]){
            cout << "N" << endl;
            return;
        }
    }
    if(n==1 && arr[0] <= 8){
        cout << "S" << endl;
        return;
    }
    cout << "S" << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

