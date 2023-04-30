#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int arr[105];
    for(int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    int ok = 0;
    if(arr[1] != arr[2] &&  arr[1] != arr[3]){
         cout << 1 << endl;
         ok = 1;
        }
    else if(arr[n] != arr[n-2] && arr[n] != arr[n-1]){
            cout << n << endl;
            ok = 1;
    }
    if(!ok){
    for(int i = 2; i < n; i++){
         if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            cout << i << endl;
            break;
            }       
    
        }       
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
    while(t--)
    solve();
	return 0;
}

