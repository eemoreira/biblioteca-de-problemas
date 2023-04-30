#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    while(k--){
        if(n%10==0) n /= 10;
        else n--;
}
    cout << n << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

