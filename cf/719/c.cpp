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

int ok2321 = 1;

bool valid(int a, int b, int c, int d, int e){
    return abs(a-b) != 1 && abs(a-c) != 1 && abs(a-d) != 1 && abs(a-e) != 1;
}

void solve(){
    int n; cin >> n;
    vector<vi> a(n+2,vi(n+2));
    for(int i = 0; i <= n+1; i++){
        for(int k = 0; k <= n+1; k++){
            a[i][k] = 1e9;
        }
    }   
    map<int,int> jafoi;
    for(int i = 1; i <= n; i++){
        for(int d = 1; d <= n; d++){
            int ok = 0;
            for(int k = 1; k <= n*n; k++){
                if(!jafoi[k] && valid(k,a[i-1][d],a[i][d-1],a[i+1][d],a[i][d+1])){
                    a[i][d] = k;
                    jafoi[k] = 1;
                    ok = 1;
                    break;
                }
            }
            /* if(!ok){ */
            /*     cout << -1 << endl; */
            /*     return; */
            /* } */
        }
    }  
    for(int i = 0; i <= n+1; i++){
        for(int k = 0; k <= n+1; k++){
            cout << a[i][k] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



