#include <bits/stdc++.h>

using namespace std;

const int MAX= 1e5;
const double pi = acos(-1);

void solve(){
    int n; cin >> n;
    double ang[MAX];
    double raio = 0;
    long long pf[MAX], dist[MAX], angs[MAX];
    for(int i = 0; i < n; i++){
         cin >> dist[i]; 
         raio += dist[i];
    }
    pf[0] = dist[0];
    for(int i = 1; i < n; i++){
        pf[i] = pf[i-1] + dist[i];
    }
    raio /= 2*pi;
    for(int i =0; i < n; i++){
        ang[i] = (double) pf[i] / raio;        
     }
    int count = 0;
    for(int i = 0; i < n; i++){
        angs[i] = (int)round(1000000*ang[i]);
        if(angs[i] == 3141593 || angs[i] == 6283185) {
            count++;  
            angs[i] = 1e9; 
    }
}
    sort(begin(angs), begin(angs) + n);
    n -= count; 
    for(int i = 0; i < n; i++) cout << angs[i] << " " ;
    int ok = 0;
    for(int i = 0; i < n; i++){
        int a=0, b = n-1;
        while(a <= b){
            int k = (a+b)/2;
            if(angs[i] == angs[k] + 3141593 && k != i){
                ok = 1;
                break;
            } 
            else if(angs[k] > angs[i] + 3141593) b = k -1;
            else a = k + 1;
         }
    }
    if(ok) cout << 'S' << endl;
    else cout << 'N' << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

