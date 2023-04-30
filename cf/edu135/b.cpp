#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    int n; cin >> n;
    if(n==4){
        cout << 2 << ' ' << 1 << ' ' << 3 << ' ' << 4 << endl;
        return;
    }
    if(n&1){
        for(int i = 4; i < n-2; i+=2){
            cout << i+1 << ' ' << i << ' ';
        }
        cout << 1 << ' ' << 2 << ' ' << 3 << ' ' << n-1 << ' ' << n << endl;
    }
    else{
        for(int i = 1; i < n-2; i+=2){
            cout <<i+1 << ' ' << i << ' ';
        }
        cout << n-1 << ' ' << n << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

