#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,h,m;cin>>n>>h>>m;
    int dormi = h*60 + m;
    int mdif = INT_MAX;
    for(int i = 0; i < n; i++){
        int a,b;cin>>a>>b;
        int temp = a*60 + b;    
        if(dormi > temp) temp = 24*60 + temp;
        mdif = min(mdif,temp - dormi);
    }
    if(mdif == 0){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    cout << mdif/60 << ' ' << mdif%60 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin>>t;
    while(t--)
    solve();
	return 0;
}

