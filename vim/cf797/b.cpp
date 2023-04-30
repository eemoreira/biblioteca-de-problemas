#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5+5;

int a[mx],b[mx],dif[mx];

void solve(){
    int n;cin>>n;
    int ok =1;
    int mdif=INT_MAX;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        dif[i] = a[i]-b[i];
        if(a[i] && b[i] && a[i] >= b[i]){
            if(dif[i] < mdif) mdif = dif[i];
        }
        if(b[i] > a[i]) ok = 0;
    }
    if(!ok){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(dif[i] == mdif ||(b[i] == 0 && dif[i] <= mdif)) continue;
        else{
            cout << "NO" << endl;
            return;
        }
    }       
    cout << "YES" << endl;


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tcc; cin >> tcc;
    while(tcc--)
    solve();
	return 0;
}

