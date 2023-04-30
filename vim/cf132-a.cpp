#include <bits/stdc++.h>

using namespace std;

void solve(){
   int x; cin >> x;
   int count =0;
   map <int,int> mp;
   for(int i = 1; i <= 3; i++){
        int a; cin >> a;
        mp[i] = a;     
    }
    int ok = 0;
    for(int i = 1; i <=3 ;i++){
        if(mp[x]){
            count++;
            x = mp[x];
        }
        else if(!mp[x] && count == 2){
             cout << "YES" << endl;  
             ok = 1;   
 }
}
    if(!ok) cout << "NO" << endl; 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
    while(t--)
    solve();
	return 0;
}

