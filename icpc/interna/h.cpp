#include <bits/stdc++.h>

using namespace std;

void solve(){
    int nportas; cin >> nportas;
    int inicial; cin >> inicial;
    double f; cin >> f;
    vector<double> a(nportas);
    int t = nportas;
    for(int i = 0; i < nportas; i++){
        double prob = (double)1/t;
        a[i] = prob * (inicial - ((double) i*i*f*f));
        t--;
    }
    double maior = a[0];
    for(int i = 0; i < nportas; i++) maior = max(maior, a[i]);
    printf("%.6lf\n", maior);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
