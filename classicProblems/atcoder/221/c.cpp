#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a;
    while(n > 0){
        a.push_back(n%10);
        n /= 10;
    }
    reverse(begin(a), end(a));
    int m = INT_MIN;    
    for(int i = 0; i < a.size(); i++){
         if(a[i] == 0) continue;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

