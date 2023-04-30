#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 1e5;

void solve(){
    int n, m; cin >> n >> m;
    ll prefixsum[MAX],prefixsum2[MAX], h[MAX];
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    prefixsum[1] = 0;
    for(int i = 2; i <= n; i++){
        if(h[i-1] > h[i]) prefixsum[i] = prefixsum[i-1] + (h[i-1] - h[i]);    
        else prefixsum[i] = prefixsum[i-1];
    }
    prefixsum2[n] = 0;
    for(int i = n-1; i >= 1; i--){
        if(h[i+1] > h[i]) prefixsum2[i] = prefixsum2[i+1] + (h[i+1] - h[i]);    
        else prefixsum2[i] = prefixsum2[i+1];
    }
    while(m--){
        int a, b; cin >> a >> b;
        if(a < b) cout << prefixsum[b] - prefixsum[a] << endl;
        else cout << prefixsum2[b] - prefixsum2[a] << endl;    
}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

