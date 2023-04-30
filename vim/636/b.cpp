#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5 + 5;

void solve(){
    int n; cin>>n;
    int arr[mx];
    int pfe[mx], pfo[mx];
    int ev[mx],odd[mx];
    ev[1] = 2;
    odd[1] = 1;
    if((n/2)%2){
        cout << "NO" << endl;
        return;
    }
    int s=ev[1];
    for(int i = 2; i <= n/2; i++){
        ev[i] = 2*i;
        s+=ev[i];
    }
    int sum = odd[1];
    if(n/2 > 2){
    for(int i = 2; i < n/2; i++){
        odd[i] = 2*i - 1;
        sum+=odd[i];
    }
    }
    int last = s - sum;
    cout << "YES" << endl;
    for(int i = 1; i <= n/2; i++) cout << ev[i] << ' ';
    for(int i = 1; i < n/2; i++) cout << odd[i] << ' ';
    cout << last << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
    while(t--)
    solve();
	return 0;
}

