#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string res="";
    int c=0;    
    for(int i = 1; i<=n; i++){
        if(c==2){
            if(i<n){
                res+="aa";
                i++;
            }   
            else res+='a';
            c=-1;
        }
        else res += 'b';
        c++;
    }  
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

