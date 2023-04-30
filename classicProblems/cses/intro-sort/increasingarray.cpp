#include <bits/stdc++.h>

void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    long long int n; cin >> n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        long long int temp; cin >> temp;
        arr[i] = temp;
    }
    long long int menor = arr[0];
    long long int count=0;
    for(int i=0;i<n;i++){
        if(arr[i] < menor){
            count += menor - arr[i];
            arr[i] += menor - arr[i];
    } 
    menor = arr[i];
    }
    cout << count << endl;
}