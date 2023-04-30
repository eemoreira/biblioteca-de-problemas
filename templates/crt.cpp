long long extgcd(int a, int b, long long& x, long long& y) {
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

pair<long long, long long> crt(vector<long long>& a, vector<long long>& m){
    if(a.size() != m.size()) return {-1,-1};
    int n = a.size();
    long long a0 = a[0];
    long long m0 = m[0];
    for(int i = 1; i < n; i++){
        long long p,q;
        extgcd(m0,m[i],p,q);
        long long md = m0*m[i];
        long long x = (a0%md*m[i]%md*q%md + a[i]%md*m0%md*p%md)%md;
        a0 = x;
        m0 = m0*m[i];
    }
    a0 += m0;
    a0 %= m0;
    return mp(a0,m0);
}
