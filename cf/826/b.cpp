#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi ans;
    if(n == 3){
        cout << - 1 << endl;
        return;
    }
    if(n == 5){
        cout << 5 << ' ' << 4 << ' ';
        for(int i = 1; i <= 3; i++) cout << i << ' ';
        cout<< endl;
        return;
    }
    if(n&1){
        for(int i = n; i >= 1; i--){
            if(i == n/2 + 1){
                cout << i-1 << ' ' << i << ' ';
                i--;
            }
            else cout << i << ' ';
        }
        cout << endl;
    }
    else{
        if(n == 4){
            cout << 3 << ' ' << 4 << ' ' << 2 << ' ' << 1;
        }
        else for(int i = n; i >= 1; i--) cout << i << ' ';
        cout << endl;
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



