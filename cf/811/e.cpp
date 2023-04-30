#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    int arr[mx];
    map<int,int> cyc;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        if(a%5==0 && a%10){
            arr[i] = a;
            cyc[arr[i]] = a + 5;
        }
        else{
            arr[i] = a % 10 == 0 ? a : (a+a%10)%20;
            if(arr[i]%10==0)cyc[arr[i]] = arr[i];
            else if(arr[i]%5==0) cyc[arr[i]] = 5;
            else if((arr[i]%2 || arr[i]%3==0 || arr[i]%7==0) && arr[i] != 1)cyc[arr[i]] = 3;
            else if(arr[i]%2==0 || arr[i] == 1) cyc[arr[i]] = 1;
        }
    }
    for(int i = 1; i < n; i++){
        if(cyc[arr[i-1]] != cyc[arr[i]]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cyc.clear();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tcc; cin>>tcc;
    while(tcc--)
    solve();
	return 0;
}

