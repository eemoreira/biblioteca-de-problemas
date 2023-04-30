#include <bits/stdc++.h>
#define ll long long
void solve();

using namespace std;

int check(int a, int b, int c, int d){
    if(a*b == c*d) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a == 0 || b == 0 || c == 0 || d == 0) cout << "N\n";
    else if(check(a,b,c,d) || check(a,c,b,d) || check(a,d,b,c)) cout << "S\n";
    else cout << "N\n";

}