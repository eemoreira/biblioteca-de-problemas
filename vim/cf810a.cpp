#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

void solve(){
    int n; cin >> n;
    int p[MAX];

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 2; i <= n; i++){
        if(p[i-1] + i-1 - (p[i-1] % (i-1)) <= n){
            int temp; temp = p[i-1];
            p[i-1] = p[i];
            p[i] = temp;    
        } 
    }
    for(int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
    cin.tie(0);
	while(t--)solve();
	return 0;
}

