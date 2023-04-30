#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;

void solve(){
   int n,m; cin >> n >> m;
   int r,c; cin >> r >> c;
   vector<string> a;
   for(int i = 0; i < n; i++){
       string s; cin >> s;
       a.push_back(s);
   }
   int okc = 0;
   int okr = 0;
   for(int i = 0; i < n; i++){
        okc |= a[i][c-1] == 'B';
   }
   for(int k = 0; k < m; k++){
        okr |= a[r-1][k] == 'B';
   }
   int ok = 0;
   for(int i = 0; i < n; i++)
        for(int k = 0; k < m; k++){
            ok |= a[i][k] == 'B'; 
        }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    else{
        int ans;
        if(okr || okc) ans = 1;
        else ans = 2;
        if(a[r-1][c-1] == 'B') ans = 0;
        cout << ans << endl;
        return;
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

