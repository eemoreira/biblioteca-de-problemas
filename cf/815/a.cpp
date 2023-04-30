#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 2e5 + 5;

void solve(){
   ll a,b,c,d; cin >> a >> b >> c >> d;
   if(b*c == a*d){
        cout << 0 << endl;
        return;
   }
   if(a == 0 && c == 0){
        cout << 0 << endl;
        return;
   }    
   else if(a == 0 || c==0){
        cout << 1 << endl;
        return;
   }
   int m = b*d;
   if((b*c)%(a*d) == 0 || (a*d)%(b*c)==0){
       cout << 1 << endl;
       return;
   }
   else{
      cout << 2 << endl;
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

