template<typename T>
struct fenwick{
    vector<T> ft;
    int n;
    fenwick(int _n) : n(_n){
        ft.resize(n + 1); // 1 indexed
    }
    T rsq(int i){
        T sum = 0;
        for(; i; i -= (i & -i)){
            sum += ft[i];
        }
        return sum;
    }
    T rsq(int i,int k){
        return rsq(k) - rsq(i-1);
    }
    void update(int i, T v){
        for(; i <= n; i += (i & -i)){
            ft[i] += v;
        }
    }
};

