#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
typedef long long ll;
 
void solve(){
    int n; cin >> n;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    int odd=1,even=2;
    if(n%2){
        cout << odd << ' ';
        odd = 3;
        while(1){
            cout << odd << ' ';
            odd+=2;
            cout << even << ' ';
            even+=2;
            if(odd>n)break;
        }
    }
    else{
        while(1){
            cout << even << ' ';
            cout << odd << ' ';
            odd+=2;
            even+=2;
            if(even>n)break;
    }
    }
    cout << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}
