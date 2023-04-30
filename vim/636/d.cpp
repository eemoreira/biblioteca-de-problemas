#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
const int mx = 2e5 + 5;

void solve(){
   int n,k;cin>>n>>k;
   map<int,int> fs;
   int arr[mx];
   for(int i = 0; i < n; i++) cin>>arr[i];
   int s=0,e=n-1;
   int pf[mx];
   for(int i = 0 ; i < n/2; i++) pf[arr[i] + arr[n-i-1]]++;
   while(s<e){
        int r1 = arr[e] + k, l1 = arr[e] + 1;
        int r2 = arr[s] + k, l2 = arr[s] + 1;
        int lb = min(l1,l2),ub = max(r2,r1);
        pf[max(r1,r2)+1]--;
        pf[min(l1,l2)]++;
        s++;e--;
   }
   cout << count << endl; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;cin>>t;
    while(t--)solve();
	return 0;
}
