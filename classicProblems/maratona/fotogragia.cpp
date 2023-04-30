#include <bits/stdc++.h>

void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){

    int a, l;
    cin >> a >> l;
    int area = a*l;
    int n; cin >> n;
    int res=-1, menor=INT_MAX;
    for(int i=1;i<=n;i++){
        int l1,l2; cin >> l1 >> l2;
        if((a <= l1 && l <= l2) || (a <= l2 && l <= l1)) {
            int x = l1*l2 - area; 
            if(x < menor){
            res = i;
            menor = x;
        }
        }
    }
    cout << res << "\n";


}

