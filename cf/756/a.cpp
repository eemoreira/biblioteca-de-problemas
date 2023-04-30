#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a;
    if(n%2==0){
        cout << 0 << endl;
        return;
    }
    while(n > 0){
        a.push_back(n%10);
        n/=10;
    }
    reverse(begin(a), end(a));
    if(a[0]%2==0){
        cout << 1 << endl;
        return;
    }
    for(int i = 0 ; i < a.size(); i++){
        if(a[i]%2==0){
            cout << 2 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tcc; cin >> tcc;
    while(tcc--)
    solve();
	return 0;
}

