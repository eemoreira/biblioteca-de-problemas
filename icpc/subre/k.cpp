#include <bits/stdc++.h>

using namespace std;



void solve(){
    int t,d,m; cin>>t>>d>>m;
    int meals[1005];
    int ok = 0;
    for(int i = 1; i <= m; i++){
        cin >> meals[i];
    }
    if(m == 0 && t <= d){
        cout << "Y" << endl;
        return;
    }
    else if (m == 0 && t > d){
        cout << "N" << endl;
        return;
    }
    meals[0] = 0;
    meals[m+1] = d;
    int difs[1005]; 
    for(int i = 1; i <= m+1 ; i++){
        difs[i] = meals[i] - meals[i-1]; 
    }
    for(int i = 1; i <= m+1; i++){
        if(difs[i] >= t){
            cout << "Y" << endl;
            ok = 1;
            break;
        }
    }
    if(!ok) cout << "N" << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

