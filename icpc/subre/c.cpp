#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5 + 5;
int num[mx], algs[mx];

void solve(){
    int b, l; cin>>b>>l;
    map<int,int> mp;
    for(int i = 1; i <= l; i++){
        cin>>algs[i];
    }
    int tb = 1;
    int n,sum=0;
    for(int i = l; i>=1; i--){
        n = (algs[i]*tb)%(b+1);
        if(n == algs[i]) mp[i] = 1; 
        tb*=b;
        sum+= n;
        tb%=(b+1);
    }
    int d = b + 1 - (sum%(b+1));
    if(sum%(b+1) == 0){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    for(int i = 1; i <= l; i++){
       if(mp[i] && algs[i] >= sum%(b+1)){
            cout << i << ' ' << algs[i] - (sum%(b+1)) << endl;
            return;
       }
       if(!mp[i] && algs[i] >= d){
            cout << i << ' ' << algs[i] - d << endl;
            return;
       }
    }  
    cout << -1 << ' ' << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

