#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    long long n1,d1,n2,d2;
    cin>>n1>>d1>>n2>>d2;
    long long n = n1*d2 + n2*d1, d = d1*d2;
    int i = 2;
    while(gcd(n,d) != 1){
        if(n%i==0 && d%i==0){
            n /= i;
            d /= i;
        }
        else{
            i++;
        }
    }
    cout << n << ' ' << d << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

