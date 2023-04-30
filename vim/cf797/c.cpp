#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5 + 5;

void solve(){
    int n; cin>>n;
    int s[mx],f[mx];
    for(int i = 0; i < n; i++)cin>>s[i];
    for(int i = 0; i < n; i++)cin>>f[i];
    for(int i = 1; i <= n; i++){
        if(i==n){
            cout << f[i-1] - s[i-1] << endl;
            break;
        }
        if(s[i] < f[i-1])s[i] = f[i-1]; 
        cout << f[i-1] - s[i-1] << ' ';
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

