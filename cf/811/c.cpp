#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int sum; cin>>sum;
    int n = 9;
    int o = sum;
    int size =0;
    while(o > 0){
        o-=n;
        size++;
        n--;
    }
    if(size==1){
        cout << sum << endl;
        return;
    }   
    int backward[10];
    n=9;
    int s=0;
    for(int i = 0; i < size-1; i++){
        backward[i] = n;
        n--;
        s+=backward[i];
    }
    cout << sum - s;
    for(int i = size-2; i>=0; i--) cout << backward[i];
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;
    while(t--)
    solve();
	return 0;
}

