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
    int ma = n/2;
    if(!(n&1)){
        for(int i = 0; i < n/2; i++){
            cout << ma - i << ' ' << n - i << ' ';
        }
        cout << endl;
    }
    if(n&1){
        for(int i = 0; i < n/2; i++){
            cout << ma - i << ' ' << n - i - 1 << ' ';
        }
        cout << n << endl;
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



