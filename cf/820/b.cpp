#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;


void solve(){
    int n; cin >> n;
    string a; cin >> a;
    map<int,int> aonde;
    for(auto i = n-1; i >= 0; i--){
        if(a[i] == '0'){
            aonde[i-2] = 1;
            i-=2;
        }
    }
    for(int i = 0; i < n ; i++){
        if(aonde[i]){
            int res = (int) ('a' + 10*((int)a[i]-'0') + (int)a[i+1]-'0' - 1);
            i+=2;
            cout << (char) res;
        }
        else{
            int res = (int) ('a' + (int)a[i]-'0' - 1);
            cout << (char) res;
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

