#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    int q=2;
    int x=1;
    int sum=0;
    while(1){
        q*=2;
        int sum = q-1;
        if(n%sum==0){
            cout << n/sum << endl;
            return;
        }
    }   
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin>>t;
    while(t--)
    solve();
	return 0;
}

