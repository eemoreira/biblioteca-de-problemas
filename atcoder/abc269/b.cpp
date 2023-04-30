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
#define eb emplace_back

int ok2321 = 0;

void solve(){
    string as[11];
    for(int i = 0; i < 10; i++){
        cin >> as[i];
    }
    int a=-1,b=-1,c=-1,d=-1;
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            if(as[i][k] == '#' && a == -1 && c == -1) a = i+1, c = k+1;
        }
    }
    for(int i = 9; i >= 0; i--){
        for(int k = 9; k >= 0; k--){
            if(as[i][k] == '#' && b==-1 && d==-1) b=i+1, d=k+1;
        }
    }
    cout << a << ' ' << b << endl << c << ' ' << d << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



