#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int s,a,b; cin >> s >> a >> b;
    for(int i = a; i < b; i++){
        int t = i,sum=0;
        while(t > 0){
            sum+=t%10;
            t /= 10;
        }
        if(sum ==s){
            cout << i << endl;
            break;
        }
    }
    for(int i = b; i>=0; i--){
        int k = i,sum2=0;
        while(k > 0){
            sum2+=k%10;
            k /= 10;
        }   
        if(sum2 == s){
            cout << i << endl;
            break;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

