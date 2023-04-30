#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;

int ok2321 = 0;
void solve(){
    ll a,b;
    for(int i = 1; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            cout << "? " << j << ' ' << i << endl;
            cin >> a;
            cout << "? " << i << ' ' << j << endl;
            cin >> b;
            if(a == -1){
                cout << "! " << max(i,j)-1 << endl;
                return;
            } 
            else if (a != b){
                cout << "! " << a+b << endl;
                return;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}

